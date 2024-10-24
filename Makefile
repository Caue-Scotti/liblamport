all: liblamport.so
	export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:./
	gcc -o programa programa.c -L./ -llamport

liblamport.so: lamport.o
	gcc -shared -o liblamport.so lamport.o

lamport.o: lamport.h
	gcc -fPIC -c lamport.c

clean:
	rm -r *.o *.so programa