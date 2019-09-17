import time

def shellsort(vetor):
    tam = len(vetor)
    salto = 1
    while(salto < tam):
        salto = 3 * salto + 1
    while salto > 0:
            for i in range(salto, tam):
                c = vetor[i]
                j = i
                while j > salto-1 and c <= vetor[j - salto]:
                    vetor[j] = vetor[j - salto]
                    j = j - salto
                vetor[j] = c
            salto = int(salto / 3)

arquivo = open('aleatorio.txt', 'r')
vetor = [int(val) for val in arquivo.readlines()]
start = time.time()
shellsort(vetor)
end = time.time()
print("tempo de execucao shellsort: " + str(end - start))