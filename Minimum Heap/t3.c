#include <stdio.h>
#include <stdlib.h>

typedef struct MinHeap MinHeap;
struct MinHeap {
    int *array;
    int tam;
    int tam_max;
};

/* funcoes utilizaveis */

MinHeap *insere_elem(MinHeap* heap, int elem);
void libera_heap(MinHeap* heap);
MinHeap *deletar_elem(MinHeap* heap, int elem);
void print_array(MinHeap* heap);
void print_tree(int array[], int arrSize);
void printAsc(MinHeap *heap);

/* funcoes auxiliares */

int index_raiz(int i);
int index_esq(int i);
int index_dir(int i);
int menor_valor(MinHeap* heap);
MinHeap *cria_heap(int tam_max);
MinHeap *fix_heap(MinHeap* heap, int index);
int find_elem(MinHeap* heap, int elem);
MinHeap *deletar_aux(MinHeap* heap);
int pow_2(int power);

int main(void){
    MinHeap *heap = cria_heap(15);

    insere_elem(heap, 15);
    insere_elem(heap, 13);
    insere_elem(heap, 11);
    insere_elem(heap, 9);
    insere_elem(heap, 7);
    insere_elem(heap, 5);
    insere_elem(heap, 3);
    insere_elem(heap, 1);
    insere_elem(heap, 14);
    insere_elem(heap, 12);
    insere_elem(heap, 10);
    insere_elem(heap, 8);
    insere_elem(heap, 6);
    insere_elem(heap, 4);
    insere_elem(heap, 2);

    puts("Primeira exibição: ");

    print_tree(heap->array, heap->tam);
    puts(" ");

    deletar_elem(heap, 1);
    deletar_elem(heap, 2);
    deletar_elem(heap, 3);
    deletar_elem(heap, 4);
    deletar_elem(heap, 5);

    puts("Segunda exibição: ");

    print_tree(heap->array, heap->tam);
    puts(" ");

    insere_elem(heap, 5);
    insere_elem(heap, 3);
    insere_elem(heap, 1);
    insere_elem(heap, 4);
    insere_elem(heap, 2);

    puts("Terceira exibição: ");

    print_tree(heap->array, heap->tam);
    puts(" ");

    puts("Ordem crescente: ");

    printAsc(heap);

    libera_heap(heap);

    return 0;
}

int index_raiz(int i) {
    return (i - 1) / 2;
}

int index_esq(int i) {
    return (2*i + 1);
}

int index_dir(int i) {
    return (2*i + 2);
}

int menor_valor(MinHeap* heap) {
    return heap->array[0];
}

MinHeap *cria_heap(int tam_max) {
    MinHeap* minheap = (MinHeap*)calloc(1, sizeof(MinHeap));
    minheap->array = (int*)calloc(tam_max, sizeof(int));
    minheap->tam_max = tam_max;
    minheap->tam = 0;
    return minheap;
}

void libera_heap(MinHeap* heap) {
    if (!heap)
        return;
    free(heap->array);
    free(heap);
}

MinHeap *insere_elem(MinHeap* heap, int elem) {
    if (heap->tam == heap->tam_max) {
        printf("Heap cheia");
        return heap;
    }

    heap->tam++;
    heap->array[heap->tam-1] = elem;
    int curr = heap->tam-1;

    while (curr > 0 && heap->array[index_raiz(curr)] > heap->array[curr]) {
        
        int aux = heap->array[index_raiz(curr)];
        heap->array[index_raiz(curr)] = heap->array[curr];
        heap->array[curr] = aux;
        curr = index_raiz(curr);
    }
    return heap; 
}

MinHeap *fix_heap(MinHeap* heap, int index) {
    if (heap->tam <= 1)
        return heap;
    
    int esq = index_esq(index); 
    int dir = index_dir(index); 

    int menor = index; 
    
    if (esq < heap->tam && heap->array[esq] < heap->array[index]) 
        menor = esq; 
    
    if (dir < heap->tam && heap->array[dir] < heap->array[menor]) 
        menor = dir; 

    if (menor != index) 
    { 
        int aux = heap->array[index];
        heap->array[index] = heap->array[menor];
        heap->array[menor] = aux;
        heap = fix_heap(heap, menor); 
    }

    return heap;
}

int find_elem(MinHeap* heap, int elem){
    for (int i = 0; i < heap->tam; i++){
        if (elem == heap->array[i]){
            return i;
        }
    }
    return -1;
}

MinHeap *deletar_aux(MinHeap* heap) {
    if (!heap || heap->tam == 0)
        return heap;

    int tam = heap->tam;
    int last_elem = heap->array[tam-1];
    
    heap->array[0] = last_elem;

    heap->tam--;
    tam--;

    heap = fix_heap(heap, 0);
    return heap;
}


MinHeap *deletar_elem(MinHeap* heap, int elem) {

    int index = find_elem(heap, elem);
    if (index == -1){
        printf("Elemento não existe");
        return heap;
    }
    heap->array[index] = menor_valor(heap) - 1;
    
    int curr = index;
    while (curr > 0 && heap->array[index_raiz(curr)] > heap->array[curr]) {

        int aux = heap->array[index_raiz(curr)];
        heap->array[index_raiz(curr)] = heap->array[curr];
        heap->array[curr] = aux;
        curr = index_raiz(curr);

    }

    heap = deletar_aux(heap);
    return heap;
}

void print_array(MinHeap* heap) {

    for (int i=0; i<heap->tam; i++) {
        printf("%d > ", heap->array[i]);
    }
    printf("\n");
}

int pow_2(int power) {
        return (1<<power);
}
    
void print_tree(int array[], int arrSize) {
    int currLevel = 0;
    int maxPerLevel = pow_2(currLevel);
    for(int i = 0; i < arrSize; i++) {
        if(i == maxPerLevel-1)
        {
            printf("\n");
            currLevel++;
            maxPerLevel = pow_2(currLevel);
        }
        printf("  %d  ",array[i]);
    }
}

void printAsc(MinHeap *heap) {
    int aux[heap->tam];
    int temp;

    for (int i = 0; i < heap->tam; i++) {
        aux[i] = heap->array[i];
    }

    for (int i = 0; i < heap->tam; ++i) {
 
            for (int j = i + 1; j < heap->tam; ++j)
            {
 
                if (aux[i] > aux[j]) 
                {
 
                    temp =  aux[i];
                    aux[i] = aux[j];
                    aux[j] = temp;
 
                }
 
            }
 
        }

    for (int i=0; i<heap->tam; i++) {
        printf("%d > ", aux[i]);
    }
    printf("\n");
}