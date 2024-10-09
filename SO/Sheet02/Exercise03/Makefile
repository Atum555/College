all: clean
	gcc -Wall -c vector.c
	ar -rc libvector.a vector.o
	gcc -Wall use_vector.c -o use_vector -L. -lvector -lm

clean:
	rm -f *.o *.a use_vector
