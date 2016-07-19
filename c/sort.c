#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int compare_int (const void *a, const void *b) {
  const int *ia = (const int *) a;
  const  int *ib = (const int *) b;
  return (*ia > *ib) - (*ia < *ib);
}

#define size 1000000
int array[size];

int main()
{
   int i;
   time_t start, end;
   double dif; 
   
   
   /* Intializes random number generator */
   srand(10);

   
   /* Print 5 random numbers from 0 to 49 */
   for( i = 0 ; i < size ; i++ ) 
   {
      array[i] = rand() % 10000;
      if (i < 5) printf("%d ", array[i]);
   }
   //time(&start);
   clock_t beginClk = clock();
   qsort (array, size, sizeof (int), compare_int);
   clock_t endClk = clock();
   double execTime = (double) (endClk - beginClk) * 1000 / CLOCKS_PER_SEC;
   //time(&end);
   //dif = difftime (end, start);

   printf("\nExec time: %lfms\n", execTime);
   //free(array);
   return(0);
}
