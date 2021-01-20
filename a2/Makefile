#  Name: Ruiqi Gao
#  NSID: rug276
#  Student#: 11199909

#  Name: Pucheng Tan
#  NSID: put178
#  Student#: 11273627

CC = gcc
CFLAGS = -g
CPPFLAGS = -std=gnu90 -Wall -pedantic
FILES = -I /student/cmpt332/pthreads
LIB = -L/student/cmpt332/pthreads/lib/Linuxx86_64


all: C D

C: reader-writer-test

PARTC_OBJS = reader-writer.o reader-writer-monitor.o libMonitor.a liblist.a

reader-writer-test: $(PARTC_OBJS)
	$(CC) -o $@ reader-writer.o reader-writer-monitor.o $(LIB) -lpthreads -L. -llist -lMonitor

reader-writer.o: reader-writer.c
	$(CC) -o $@ -c $(FILES) -I. $(CFLAGS) $(CPPFLAGS) $^

reader-writer-monitor.o: reader-writer-monitor.c
	$(CC) -o $@ -c $(FILES) -I. $(CFLAGS) $(CPPFLAGS) $^

libMonitor.a: Monitor.o
	ar rcs $@ $^

Monitor.o: Monitor.c
	$(CC) -o $@ -c $(FILES) -I. $(CFLAGS) $(CPPFLAGS) $^

# The following commands are for creating the library liblist.a

LIST_OBJS = list_adders.o list_movers.o list_removers.o

liblist.a: $(LIST_OBJS)
	ar rcs $@ $^

list_adders.o: list_adders.c
	$(CC) -o $@ -c $(CFLAGS) $(CPPFLAGS) $^

list_movers.o: list_movers.c
	$(CC) -o $@ -c $(CFLAGS) $(CPPFLAGS) $^

list_removers.o: list_removers.c
	$(CC) -o $@ -c $(CFLAGS) $(CPPFLAGS) $^



D: s-chat
s-chat.o: s-chat.c
	$(CC) -o s-chat.o -c $(CFLAGS) $(CPPFLAGS) s-chat.c $(FILES) -I.
s-chat: s-chat.o liblist.a
	$(CC) -o s-chat s-chat.o $(LIB) -lpthread -lrt -L. -llist

clean:
	rm -rf *.o *.a reader-writer-test s-chat
