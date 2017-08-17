void insertion_sort (int vetor[], int max) {
      int i, j, aux;
      for (i = 1; i < max; i++) {
            j = i;
            while (j > 0 && vetor[j - 1] > vetor[j]) {
                  aux = vetor[j];
                  vetor[j] = vetor[j - 1];
                  vetor[j - 1] = aux;
                  j--;
            }
      }
}