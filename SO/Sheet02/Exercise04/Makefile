all: clean
	gcc -Wall -c list.c
	ar -rc liblist.a list.o
	rm -f list.o
	gcc -Wall use_list.c -o use_list -L. -llist -lm

shared: clean
	gcc -Wall -c -fPIC list.c
	gcc -shared -o liblist.so list.o
	rm -f list.o
	gcc -Wall use_list.c -o use_list -L. -llist -lm

clean:
	rm -f *.o *.a *.so use_list
