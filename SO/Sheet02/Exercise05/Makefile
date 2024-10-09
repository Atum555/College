all: clean
	gcc -Wall -c complex*.c
	ar -rc libcomplex.a complex*.o
	rm -f complex*.o
	gcc -Wall use_complex.c -o use_complex -L. -lcomplex -lm

shared: clean
	gcc -Wall -c -fPIC complex*.c
	gcc -shared -o libcomplex.so complex*.o
	rm -f complex*.o
	gcc -Wall use_complex.c -o use_complex -L. -lcomplex -lm

clean:
	rm -f *.o *.a *.so use_complex
