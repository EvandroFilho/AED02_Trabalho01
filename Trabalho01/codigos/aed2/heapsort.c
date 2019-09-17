//referencia: https://www.geeksforgeeks.org/heap-sort/
//https://www.ime.usp.br/~pf/algoritmos/aulas/hpsrt.html
#include <stdio.h>
#include <time.h>
     
clock_t inicio, fim;
double total;

//Função para trocar dois valores do vetor
void troca(int vetor[], int i, int j){
    int temp = vetor[i];
    vetor[i] = vetor[j];
    vetor[j] = temp;
}

//função para imprimir o vetor
void mostrarVetor(int vetor[], int tam) 
{ 
	for (int i=0; i<tam; ++i) 
        printf("%d, ", vetor[i]);
    printf("\n");
} 

//rearranja os elementos de um vetor (ou subvetor) para que ele se torne um heap
void constroiHeap(int vetor[], int tam, int i) 
{ 
	int maior = i; // o elemento raiz que estamos verificando
	int esq = 2*i + 1; // o filho esquerdo dele no heap
	int dir = 2*i + 2; // o filho direito dele no heap
	// verifica se o filho esquerdo é maior que a raiz
	if (esq < tam && vetor[esq] > vetor[maior]) 
		maior = esq; 
	// verifica se o filho direito é maior que a raiz
	if (dir < tam && vetor[dir] > vetor[maior]) 
		maior = dir; 
	// se o maior elemento nao é a raiz 
	if (maior != i) 
	{ 
		troca(vetor, i, maior); 
		// recursivamente corrige o nó alterado
		constroiHeap(vetor, tam, maior); 
	} 
} 

// função princiapl do heapSort
void heapSort(int vetor[], int tam) 
{ 
	// corrige o vetor para heap
	for (int i = tam / 2 - 1; i >= 0; i--) 
		constroiHeap(vetor, tam, i); 
	// corrige as sub arvores do heap de baixo pra cima
	for (int i=tam-1; i>=0; i--) 
	{ 
		// move a raiz atual para o fim
		troca(vetor, 0, i); 
		// executa o constroiHeap na subarvore deste elemento;
		constroiHeap(vetor, i, 0); 
	} 
} 

// Driver program 
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
	heapSort(vetor, tam); 
	fim = clock();
	total = ((double) (fim - inicio)) / CLOCKS_PER_SEC;
	printf("tempo de execucao heapsort: %f", total);
	
} 
