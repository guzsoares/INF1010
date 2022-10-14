#include <stdio.h>
#include <stdlib.h>

typedef struct heap {
    int tamanho; 
    int pos; 
    int* prioridade; 
}Heap;


Heap* heap_cria(int tamanho);



Heap* heap_cria(int tamanho){
    Heap* heap=(Heap*)malloc(sizeof(Heap));
    heap->tamanho=tamanho;
    heap->pos=0;
    heap->prioridade=(int *)malloc(tamanho*sizeof(int));
    return heap;
}
void print(Heap *h){
    int i;
    printf("____________Print Heap_____________\n");
    for(i=0;i< h->tamanho;i++){
        printf("-> %d ",h->prioridade[i]);
    }
    printf("->__/\\__\n");
}

int main (void){




    return 0;
}