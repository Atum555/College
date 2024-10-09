all:
	gcc -c -Wall -fPIC complex_*.c
	gcc -shared -o libcomplex.so complex_*.o   
	gcc -Wall use_complex.c -o use_complex -L. -lcomplex -lm

clean:
	rm -f *.o *.a *.so use_complex 
