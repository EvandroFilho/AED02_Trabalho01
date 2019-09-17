//referencia: https://pt.wikipedia.org/wiki/Shell_sort
#include <stdio.h>
#include <time.h>
     
clock_t inicio, fim;
double total;

//função para imprimir o vetor
void mostrarVetor(int vetor[], int tam) 
{ 
	for (int i=0; i<tam; ++i) 
        printf("%d, ", vetor[i]);
    printf("\n");
} 


void shellSort(int vetor[], int tam) {
    int i , j , valor;
 
    int salto = 1;
    while(salto < tam) {
        salto = 3 * salto + 1; //inicializa o salto com um valor alto
    }
    while (salto > 0) {
        for(i = salto; i < tam; i++) { // faz uma varredura no vetor a partir do salto
            valor = vetor[i];
            j = i;
            while (j > salto-1 && valor <= vetor[j - salto]) {
                vetor[j] = vetor[j - salto];
                j = j - salto;
            }
            vetor[j] = valor;
        }
        salto = salto/3;
    }
}

int main() 
{ 
	int vetor[100000];
	FILE* arquivo = fopen ("aleatorio.txt", "r");
	int i = 0;
	int valor = 0;
	fscanf (arquivo, "%d", &valor);    
	while (!feof (arquivo))
	{  
		vetor[i] = valor;
		i++;
		fscanf (arquivo, "%d", &valor);      
	}
	fclose (arquivo); 

	int tam = sizeof(vetor)/sizeof(vetor[0]); 
	inicio = clock();
	shellSort(vetor, tam); 
	fim = clock();
	total = ((double) (fim - inicio)) / CLOCKS_PER_SEC;
	printf("tempo de execucao shellsort: %f", total);
} 