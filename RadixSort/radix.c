#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define NUM_ELEMENTOS 101
#define RANGE 10000


int get_max(int a[], int num_elements){
   int i, max= a[0];
   for (i=0; i<num_elements; i++)
   {
  if (a[i]>max)
  {
     max=a[i];
  }
   }
   return(max);
}


void radix(int v[], int size) {
    int i;
    int *b;
    int maior = get_max(v,size);
    int exp = 1;

    b = (int *)calloc(size, sizeof(int));

    while (maior/exp > 0) {
        int bucket[RANGE] = { 0 };
      for (i = 0; i < size; i++)
          bucket[(v[i] / exp) % 10]++; 
      for (i = 1; i < 10; i++)
          bucket[i] += bucket[i - 1];
      for (i = size - 1; i >= 0; i--)
          b[--bucket[(v[i] / exp) % 10]] = v[i];
      for (i = 0; i < size; i++)
          v[i] = b[i];
      exp *= 10;
    }


}



int main(){
  int x;
  int vetor[NUM_ELEMENTOS];
  FILE *arq;
  int range;

  arq = fopen( "couting.txt", "r" );

  int i = 0;
  while (!feof(arq))
    {
      fscanf( arq, "%d", &x );
      vetor[i] = x;
      i++;   
    }
      fclose(arq);       

      radix(vetor,NUM_ELEMENTOS);
      
      for(i = 0; i < NUM_ELEMENTOS;i++){
        printf("%d\n", vetor[i]);
      
      }


}
