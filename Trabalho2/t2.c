#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int central;
    struct node *maior;
    struct node *menor;
}Node;

Node *insere(int valor, Node *arvore);

int main(void){
    Node *ab =  NULL;
    Node *abb = NULL;

    //questao 2
    insere(10, abb);
    insere(5, abb);
    insere(7, abb);
    insere(1, abb);
    insere(13, abb);
    insere(15, abb);


    return 0;
}


Node *insere(int valor, Node *arvore){
    Node *aux;

    if(arvore == NULL){
        aux =(Node*)malloc(sizeof(Node)); //inicializa a arvore
        aux->maior = NULL;
        aux->menor = NULL;
        aux->central = valor; //primeiro valor
        arvore = aux; //inicializa a arvore, para continuar o loop

    }else{
        if(valor > arvore->central){
            arvore->maior = insere(valor,arvore->maior);

        }
        if(valor< arvore->central){
            arvore->menor = insere(valor, arvore->menor);
        }
    }
    return arvore;
}