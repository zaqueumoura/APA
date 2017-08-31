#include <stdio.h>
#include <stdlib.h>

void merge(int *v, int inicio, int fim) {
    int i, j, k, meiotam, *vTemp;

    if(inicio == fim) return;

    meiotam = (inicio + fim ) / 2;
    merge(v, inicio, meiotam);
    merge(v, meiotam + 1, fim);

    i = inicio;
    j = meiotam + 1;
    k = 0;
    vTemp = (int *) malloc(sizeof(int) * (fim - inicio + 1));

    while(i < meiotam + 1 || j  < fim + 1) {
        if (i == meiotam + 1 ) { 
            vTemp[k] = v[j];
            j++;
            k++;
        }
        else {
            if (j == fim + 1) { 
                vTemp[k] = v[i];
                i++;
                k++;
            }
            else {
                if (v[i] < v[j]) {
                    vTemp[k] = v[i];
                    i++;
                    k++;
                }
                else {
                    vTemp[k] = v[j];
                    j++;
                    k++;
                }
            }
        }

    }

    for(i = inicio; i <= fim; i++) {
        v[i] = vTemp[i - inicio];
    }


}



int main() {
	int size,i;
	printf("Digite o tamanho do vetor para ser ordenado\n");
	scanf("%d",&size);
	int *vetor = (int*) malloc(sizeof(int)*size);

	for(i = 0;i < size;i++){
		printf("Digite um numero\n");
		scanf("%d",&vetor[i]);	

	}


	merge(vetor,0,size-1);
	

	for(i = 0;i < size;i++){
		printf("%d\n\n", vetor[i]);

	}



}