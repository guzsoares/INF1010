#include <stdio.h>
#include <stdlib.h>

typedef struct heap {
    int max; 
    int pos; 
    int* prioridade; 
}Heap;


Heap* heap_cria(int max);



Heap* heap_cria(int max){
    Heap* heap=(Heap*)malloc(sizeof(Heap));
    heap->max=max;
    heap->pos=0;
    heap->prioridade=(int *)malloc(max*sizeof(int));
    return heap;
}


int main (void){




    return 0;
}