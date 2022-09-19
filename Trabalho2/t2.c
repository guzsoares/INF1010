#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int central;
    struct node *direita;
    struct node *esquerda;
}Node;

Node *insereABB(int valor, Node *arvore);
Node* retiraABB(Node* r, int num);
void insereAB(Node *pai, Node *filho);
Node *criaAB(int num);
void print2DUtil(Node *root, int space);
void print2D(Node *root);

int main(void){
    Node *abb = NULL;

    //questao 2
    insereABB(10, abb);
    insereABB(5, abb);
    insereABB(7, abb);
    insereABB(1, abb);
    insereABB(13, abb);
    insereABB(15, abb);

    printf("\n");
    print2D(abb);
    return 0;
}

Node *insereABB(int valor, Node *arvore){
    Node *aux;
    if(arvore == NULL){
        aux =(Node*)malloc(sizeof(Node)); //inicializa a arvore
        aux->direita = NULL;
        aux->esquerda = NULL;
        aux->central = valor; //primeiro valor
        arvore = aux; //inicializa a arvore, para continuar o loop
    }else{
        if(valor > arvore->central){
            arvore->direita = insereABB(valor,arvore->direita);
        }
        if(valor< arvore->central){
            arvore->esquerda = insereABB(valor, arvore->esquerda);
        }
    }
    return arvore;
}
//Essa funcao retira um no escolhido de maneira recursiva (ABB)
Node* retiraABB(Node* r, int num){
    if (r == NULL)
        return NULL;
    else if (r->central > num)
        r->esquerda = retiraABB(r->esquerda, num);
    else if (r->central < num)
        r->direita = retiraABB(r->direita, num);
    else { 
        if (r->esquerda == NULL && r->direita == NULL) {
            free (r);
            r = NULL;
        }else if (r->esquerda == NULL){
            Node* t = r;
            r = r->direita;
            free (t);
        }else if (r->direita == NULL){
            Node* t = r;
            r = r->esquerda;
            free (t);
        }else{
            Node* f = r->esquerda;
            while (f->direita != NULL){
                f = f->direita;
            }
            r->central = f->central; 
            f->central = num;
            r->esquerda = retiraABB(r->esquerda,num);
        }
    }
    return r;
}
//Essa funcao conecta uma subarvore(filho) a arvore, de maneira arbitraria
void insereAB(Node *pai, Node *filho){
    filho->direita = pai->esquerda;
    pai->esquerda = filho;
}

void print2DUtil(Node *root, int space){
    // Base case
    if (root == NULL)
        return;
    space += 10;
    print2DUtil(root->direita, space);
 
    printf("\n");
    for (int i = 10; i < space; i++)
        printf(" ");
    printf("%d\n", root->central);
 
   print2DUtil(root->esquerda, space);
}
 

void print2D(Node *root){
   print2DUtil(root, 0);
}