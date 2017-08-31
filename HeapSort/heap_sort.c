#include <stdio.h>
#include <stdlib.h>


void heap(int v[], int n) {
   int i = n / 2, pai, filho, t;
   while(1) {
      if (i > 0) {
          i--;
          t = v[i];
      } else {
          n--;
          if (n == 0) return;
          t = v[n];
          v[n] = v[0];
      }
      pai = i;
      filho = i * 2 + 1;
      while (filho < n) {
          if ((filho + 1 < n)  &&  (v[filho + 1] > v[filho]))
              filho++;
          if (v[filho] > t) {
             v[pai] = v[filho];
             pai = filho;
             filho = pai * 2 + 1;
          } else {
             break;
          }
      }
      v[pai] = t;
   }
}

int main(){
  int i, size;

  printf("Digite o tamanho do vetor\n");
  scanf("%d",&size);

  int *vetor = (int*) malloc(sizeof(int)*size);

  for(i = 0; i < size; i++){
    printf("Digite um numero\n");
    scanf("%d",&vetor[i]);
  }

  heap(vetor,size);

  for(i = 0; i< size; i++)
    printf("%d\n",vetor[i]);

}


