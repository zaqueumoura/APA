#include <stdio.h>
#include "insertion_sort.h"


 void imprimeVetor(int vetor[], int max){ 
  int i = 0;

  for (i = 0; i < max; i++) {
    printf ("%d ",vetor[i]);
  }
  printf ("\n");
}


int main () {
  int max, i;
  printf("Digite o tamanho do vetor\n");
  scanf ("%d",&max); 
  int  vetor[max];
  
  for (i = 0; i < max; i++) {
    printf("Digite os numeros do vetor\n");
    scanf ("%d",&vetor[i]);
  }
  
  insertion_sort (vetor, max);
  imprimeVetor(vetor, max); 
}