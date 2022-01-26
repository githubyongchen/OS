CC = gcc
OBJ = simple-shell

$(OBJ):$(OBJ).o
	$(CC) -o $@ $^

%.o:%.c
	$(CC) -c -o $@ $^

clean: 
	rm -f $(OBJ) *.o
