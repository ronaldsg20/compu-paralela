#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <omp.h>
#define THREADS 4
#define IT 40000000000
//global variables
double *vsum;

int main(int argc, char **argv)
{

    /* vsum = malloc((THREADS+1) * sizeof(*vsum));
    if(vsum == NULL) {
        fprintf(stderr, "Memory allocation problem\n");
        exit(1);
    } */

/*     for(int p=0; p<=THREADS; p++)        //initialize array to 0
    {
        vsum[p] = 0.0;
    } */

    double pi = 0.0;
    //launch threads

    //int j = omp_get_thread_num();    
    //unsigned long int ini = (int)(IT/THREADS)*j;
    //unsigned long int fin = (int)(IT/THREADS)+ini;
    
     

    #pragma omp parallel for num_threads(THREADS) schedule(runtime) reduction(+:pi)
        for(unsigned long int i = 0; i < IT; i++)
        {
            if(i % 2 == 0){
                pi += 4.0/((2*i)+1); 
                
                }
            else{
                pi -= 4.0/((2*i)+1);
                
            }
        }
        //int j = omp_get_thread_num();
        //printf("[%d] : %.20f \n",j,pi);

    /* for(int x=0; x<THREADS; x++)
    {
	printf("[%d] : %.20f\n",x, vsum[x]);
        pi += vsum[x];

    } */

    printf("pi  : %.20f\n", pi);

    //sfree(vsum);
}
