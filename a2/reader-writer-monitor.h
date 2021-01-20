/* 
#  Name: Ruiqi Gao
#  NSID: rug276
#  Student#: 11199909

#  Name: Pucheng Tan
#  NSID: put178
#  Student#: 11273627
*/

#ifndef READER_WRITER_MONITOR_H_
#define READER_WRITER_MONITOR_H_

void Initialize(void);
void StartRead(void);
void StopRead(void);
void StartWrite(void);
void StopWrite(void);
PID reader(void *);
PID writer(void *);

#endif /* READER_WRITER_MONITOR_H_ */