CC = gcc
LIB = -lpthread
EXE0 = helloworld_pthreads.exe
EXE1 = producer_consumer_model.exe
EXE2 = pthreads_findmin.exe
EXE3 = pthreads_pi.exe

%.exe : %.o
	$(CC) $(LIB) -o $@ $^

%.o : %.c
	$(CC) $(LIB) -c -o $@ $^

all: $(EXE0) $(EXE1) $(EXE2) $(EXE3)

clean:
	rm -f *.exe *.o
