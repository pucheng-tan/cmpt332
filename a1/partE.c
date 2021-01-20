#include "partE.h"

#define PATH_MAX 4096
#define NAME_MAX 256
#define INPUT_MAX 4096
#define DELIM " \t\r\n\a"


void shell(){

    char *command;
    char **paraArr;
    int numPara;
    pid_t childPid;
    int status;

    input = malloc(sizeof(char) * INPUT_MAX);
    command = NULL;
    paraArr = malloc(sizeof(char*));

    while (1){     
        prompt();
        numPara = readCommand(&command, paraArr);
        if(numPara == -1){
			continue;
		}
        if(strcmp(command, "cd") == 0 ||
            strcmp(command, "quit") == 0 ||
            strcmp(command, "exit") == 0)
        {
            builtIn(command, paraArr);
            continue;
        }
        childPid = fork();
        if (childPid == 0) {
            if (execute(command, paraArr) == -1){
                perror("error");
            }
            exit(0);
        }
        else if(childPid < 0){
            perror("error");
        }else {
            do {
                waitpid(childPid, &status, WUNTRACED);
            }
            while (!WIFEXITED(status) && !WIFSIGNALED(status));
            
        }
        
    }
    
    
}

void prompt(){
    pwd = getpwuid(getuid());
    char cwd[PATH_MAX];
    if (getcwd(cwd, sizeof(cwd)) != NULL) {
       printf("%s> ", cwd);
   }    
}

int readCommand(char **command, char **paraArr){
    char *readLine;
    char *new;
    int len = 0;
    int i = 0;
    readLine = fgets(input, INPUT_MAX, stdin);
    if(readLine == NULL){
		printf("\n");
		exit(0);
	}
    else if(strcmp(readLine, "\n") == 0){
        return -1;
    }
    else{
        new = strtok(readLine, DELIM);      
        while(new != NULL)
        {
            paraArr[i++] = new;
            paraArr = realloc(paraArr, sizeof(char *) * (i + 1));
            new = strtok(NULL, DELIM);
            len++;
        }
        paraArr = realloc(paraArr, sizeof(char *) * (i + 1));
        paraArr[i++] = NULL;

        //printf("%s",paraArr[0]);
        //printf("%s",paraArr[1]);
        //printf("%s",paraArr[2]);

        *command = paraArr[0];
    }

    return len;

}

void builtIn(char *command, char **paraArr){
    char *cdPath;
    cdPath = NULL;

    if(strcmp(command, "cd") == 0){
        if(paraArr[1][0] == '~'){
			cdPath = malloc(strlen(pwd->pw_dir) + strlen(paraArr[1]));
			strcpy(cdPath, pwd->pw_dir);
			strncpy(cdPath+strlen(pwd->pw_dir), paraArr[1] + 1,strlen(paraArr[1]));
		}else{
            cdPath = paraArr[1];
        }
        
        //printf("%s",cdPath);
        if(chdir(cdPath) != 0){
            printf("No such file or directory\n");
        }
        
    }
    else if(strcmp(command, "quit") == 0 || strcmp(command, "exit") == 0){
        printf("Shell exits.\n");
		exit(0);
    }
}

int execute(char *command, char **paraArr){
    char *commandLoc[3];
    int executed = -1;
    int i;
    char *path;
    commandLoc[0] = "/bin/";
    commandLoc[1] = "/usr/bin/";
    commandLoc[2] = "/usr/local/bin/";
    path = (char*)malloc(sizeof(char) * PATH_MAX );  
    for(i = 0; (i < 3) && (executed == -1); i++){
        strcpy(path,commandLoc[i]);
		strcat(path,command);
        if(execv(path, paraArr) == -1){
        	executed = -1;
        }
		else{
			executed = 1;
		}        
    }
    if (executed == -1){
        printf("%s: command not found\n",command);	
    }
    return executed;
}

int main(){	
	shell();     
	return 0;
}