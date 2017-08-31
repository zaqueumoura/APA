#include <stdio.h>
#include <stdlib.h>

void quick(int * v, int inicio, int fim){
	int i, j, pivo, aux;
	i = inicio;
	j = fim;
	pivo = v[(inicio + fim)/2];
	while(i<j){
		while(v[i] < pivo) 
			i++;
		while(v[j] > pivo) 
			j--;
		if(i <= j){
			aux = v[i];
			v[i++] = v[j];
			v[j--] = aux;
		}
	}
	if(j > inicio) 
		quick(v, inicio, j);
	if(i < fim) 
		quick(v, i, fim);

	return;
}


int main(){
	int size, i;

	printf("Digite o tamanho do vetor\n");
	scanf("%d",&size);

	int *vetor = (int*) malloc(sizeof(int)*size);
	
	

	for(i = 0;i < size;i++){
		printf("Digite um numero\n");
		scanf("%d",&vetor[i]);
	}
	quick(vetor,0,size-1);

	for(i = 0;i < size; i++)
		printf("%d\n\n",vetor[i]);



}

