CC = gcc
OBJ = proc_creation

$(OBJ):$(OBJ).o
	$(CC) -o $@ $^

%.o:%.c
	$(CC) -c -o $@ $^

clean: 
	rm -f $(OBJ) *.o
