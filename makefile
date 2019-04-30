all:
	#gcc -pthread pi.c -o pi
	gcc -fopenmp pi-omp-2.c -o pi-omp

