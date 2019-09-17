import time

def constroi_heap(vetor, tam, i):
    maior = i
    esq = 2*i +1
    dir = 2*i +2
    if esq < tam and vetor[esq] > vetor[maior]:
        maior = esq
    if dir < tam and vetor[dir] > vetor[maior]:
        maior = dir

    if maior != i:
        vetor[i], vetor[maior] = vetor[maior], vetor[i]
        constroi_heap(vetor, tam, maior)
    #print(vetor)



def heapsort(vetor):
    tam = len(vetor)
    for i in range(int(tam/2)-1, -1, -1):
        constroi_heap(vetor, tam, i)

    for i in range(tam-1, -1, -1):
        vetor[i], vetor[0] = vetor[0], vetor[i]
        constroi_heap(vetor, i, 0)
    return vetor

arquivo = open('aleatorio.txt', 'r')
vetor = [int(val) for val in arquivo.readlines()]
start = time.time()
heapsort(vetor)
end = time.time()
print("tempo de execucao heapsort: " + str(end - start))