#  Name: Ruiqi Gao
#  NSID: rug276
#  Student#: 11199909

#  Name: Pucheng Tan
#  NSID: put178
#  Student#: 11273627

CC = gcc
CFLAGS = -g
CPPFLAGS = -std=gnu90 -std=c99 -Wall -pedantic
FILES = -I /student/cmpt332/pthreads
LIB = -L/student/cmpt332/pthreads/lib/Linuxx86_64

all: A1 A2 C E

A1: partA1

square.o: square.c
	$(CC) -o square.o -c $(CPPFLAGS) $(CFLAGS) square.c

partA1.o: partA1.c
	$(CC) -o partA1.o -c $(CFLAGS) $(CPPFLAGS) $(FILES) -I. partA1.c

libsquare.a: square.o
	ar -rcs libsquare.a square.o
	
partA1: partA1.o libsquare.a
	$(CC) -o partA1 partA1.o $(LIB) -lpthreads -L. -lsquare
	

A2: partA2

partA2.o: partA2.c
	$(CC) -o partA2.o -c $(CFLAGS) $(CPPFLAGS) $(FILES) -I. partA2.c

partA2: partA2.o libsquare.a
	$(CC) -o partA2 partA2.o $(LIB) -lpthread -L. -lsquare


C: group17-testlist testlist

OBJS = list_adders.o list_movers.o list_removers.o

testlist: testlist.o liblist.a
	$(CC) -o $@ testlist.o -L. -llist

testlist.o: testlist.c
	$(CC) -o $@ -c $(FILES) -I. $(CFLAGS) $(CPPFLAGS) $^

group17-testlist: group17-testlist.o liblist.a
	$(CC) -o $@ group17-testlist.o -L. -llist

group17-testlist.o: group17-testlist.c
	$(CC) -o $@ -c $(FILES) -I. $(CFLAGS) $(CPPFLAGS) $^

liblist.a: $(OBJS)
	ar rcs $@ $^

list_adders.o: list_adders.c
	$(CC) -o $@ -c $(FILES) -I. $(CFLAGS) $(CPPFLAGS) $^

list_movers.o: list_movers.c
	$(CC) -o $@ -c $(FILES) -I. $(CFLAGS) $(CPPFLAGS) $^

list_removers.o: list_removers.c
	$(CC) -o $@ -c $(FILES) -I. $(CFLAGS) $(CPPFLAGS) $^


E: partE

partE.o: partE.c
	$(CC) -o partE.o -c  $(CFLAGS) $(CPPFLAGS) partE.c
partE: partE.o
	$(CC) -o partE $(CFLAGS) $(CPPFLAGS) partE.o

clean:
	rm -rf *.o *.a partA1 partA2 group17-testlist testlist
