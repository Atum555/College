all:
	gcc -Wall -c complex_*.c
	ar -rc libcomplex.a complex_*.o
	gcc -Wall use_complex.c -o use_complex -L. -lcomplex -lm

clean:
	rm *.o *.a use_complex
