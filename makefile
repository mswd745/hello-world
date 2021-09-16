myprog : test.o printUtil.o
	gcc -g -o myprog test.o printUtil.o

test.o : test.c printUtil.h
	gcc -g -c test.c

printUtil.o : printUtil.c printUtil.h
	gcc -g -c printUtil.c

clean:
	rm -f *.o
