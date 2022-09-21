#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int central;
    struct node *direita;
    struct node *esquerda;
}Node;

Node *insereABB(int valor, Node *arvore);
Node* retiraElemento(Node* r, int chave);
Node *insereArvoreQ1(int valor, Node *arvore, int isRight);
Node *criaAB(int chave);
int alturaArvore(Node * root);
int isBinaryLogic(Node *arvore);
void buscaABB(Node *arvore, int chave);
void buscaAB(Node* arvore, int chave);
void printAltura(Node * root, int level);
void printArvoreNivel(Node * root);
void isBinary(Node *arvore);
void mostraPreOrdem(Node *arvore);
void mostraPosOrdem(Node *arvore);
void mostraSimetrica(Node *arvore);
void imprimeDados(Node *arvore);



int main(void){
    Node *abb = NULL;
    Node *arvore_q1 = NULL;

    //questao 1
    arvore_q1 = insereArvoreQ1(10, arvore_q1, 0);
    arvore_q1 = insereArvoreQ1(5, arvore_q1, 0);
    arvore_q1 = insereArvoreQ1(13, arvore_q1, 1);
    arvore_q1 = insereArvoreQ1(15, arvore_q1, 1);
    arvore_q1 = insereArvoreQ1(7, arvore_q1, 0);
    arvore_q1 = insereArvoreQ1(1, arvore_q1, 0);

    //questao 2
    abb = insereABB(10, abb);
    abb = insereABB(5, abb);
    abb = insereABB(7, abb);
    abb = insereABB(1, abb);
    abb = insereABB(13, abb);
    abb = insereABB(15, abb);


    printf("QUESTAO 4:\n");
    printf("Árvore 1: (AB) \n\n");
    printf("PRE ORDEM:\n\n");
    mostraPreOrdem(arvore_q1);
    printf("Árvore 2: (ABB) \n\n");
    mostraPreOrdem(abb);

    printf("Arvore 1: (AB)\n\n");
    printf("EM NIVEL:\n\n");
    printArvoreNivel(arvore_q1);
    printf("Arvore 2: (ABB)\n\n");
    printf("EM NIVEL:\n\n");
    printArvoreNivel(abb);

    printf("QUESTAO 5\n");
    puts("");
    printf("Arvore 1 - ");
    isBinary(arvore_q1);
    printf("Arvore 2 - ");
    isBinary(abb);

    printf("QUESTAO 6\n");
    puts("Altura da arvore 1");
    int x = alturaArvore(arvore_q1);
    printf("%d\n",x);
    puts("Altura da arvore 2");
    int h = alturaArvore(abb);
    printf("%d\n\n",h);

    printf("QUESTAO 7\n");
    printf("Busca Arvore 1\n");
    buscaAB(arvore_q1, 7);
    printf("Busca Arvore 2\n");
    buscaABB(abb, 7);

    printf("questao 8\n");
    puts("");
    abb = retiraElemento(abb, 1);
    printf("Primeira exclusao\n");

    printArvoreNivel(abb);

    abb = retiraElemento(abb, 13);
    printf("Segunda exclusao\n");

    printArvoreNivel(abb);

    abb = retiraElemento(abb, 10);
    printf("Terceira exclusao\n");

    printArvoreNivel(abb);


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

Node *insereArvoreQ1(int valor, Node *arvore, int isRight){
    Node *aux;
    if(arvore == NULL){
        aux =(Node*)malloc(sizeof(Node)); //inicializa a arvore
        aux->direita = NULL;
        aux->esquerda = NULL;
        aux->central = valor; //primeiro valor
        arvore = aux; //inicializa a arvore, para continuar o loop
    } else {
        if (isRight == 1){
        arvore->direita = insereArvoreQ1(valor, arvore->direita, 0);
        }
        else {
        arvore->esquerda = insereArvoreQ1(valor, arvore->esquerda, 1);
        }
    }

    return arvore;
}

Node* retiraElemento(Node *arvore, int chave) {
    if(arvore == NULL){
        printf("Elemento não está na árvore.\n");
        return NULL;
    } else {
        if(arvore->central == chave) {
            if(arvore->esquerda == NULL && arvore->direita == NULL) {
                free(arvore);
                return NULL;
            }
            else{
            }
        } else {
            if(chave < arvore->central)
                arvore->esquerda = retiraElemento(arvore->esquerda, chave);
            else
                arvore->direita = retiraElemento(arvore->direita, chave);
            return arvore;
        }
    }
    return arvore;
}

void printArvoreNivel(Node * root){
    if (root == NULL){
        return;
    }

    int h = alturaArvore(root);
    int i;
    for (i = 0; i <= h; i++){
        printAltura(root, i);
        printf("\n");
    }
}

void printAltura(Node * root, int level){

    if (root == NULL){
        return;
    }
    if (level == 1){
        imprimeDados(root);
    }
    else if (level > 1) {
        printAltura(root->esquerda, level - 1);
        printAltura(root->direita, level - 1);
    }
}

int alturaArvore(Node * root){
    if (root == NULL){
        return 0;
    }

    int leftHeight = alturaArvore(root->esquerda);
    int rightHeight = alturaArvore(root->direita);
    if (leftHeight > rightHeight){
        return leftHeight + 1;
    }
    if (rightHeight > leftHeight){
        return rightHeight + 1;
    }
    return leftHeight + 1;
}


int isBinaryLogic(Node* arvore)
{
    if (arvore == NULL)
        return 1;
 
    if (arvore->esquerda != NULL && arvore->esquerda->central > arvore->central)
        return 0;
 
    if (arvore->direita != NULL && arvore->direita->central < arvore->central)
        return 0;
 
    if (!isBinaryLogic(arvore->esquerda) || !isBinaryLogic(arvore->direita))
        return 0;
 
    return 1;
}

void isBinary(Node *arvore){
    int value = isBinaryLogic(arvore);
    if (value  == 1){
        printf("E binaria\n");
    } 
    else {
        printf("Nao e binaria\n");
    }
}

void buscaABB(Node *arvore, int chave){
    while(arvore->central != chave){
        if(arvore->central == chave){
            break;
        } else if(arvore->central > chave){
            arvore = arvore->esquerda;
        } else if(arvore->central < chave){
            arvore = arvore->direita;
        } else {
            printf("Elemento não encontrado");
            break;
        } 
    }
    imprimeDados(arvore);
}


void buscaAB(Node* arvore, int chave){
    if(arvore==NULL){
        return;
    }else if(arvore->central == chave){
        imprimeDados(arvore);
    }else{
        buscaAB(arvore->direita, chave);
        buscaAB(arvore->esquerda, chave);
    }
}

void mostraPreOrdem(Node *arvore){ //comeca da arvore e printa tudo da esquerda, depois da direita 
    if(arvore != NULL){
        imprimeDados(arvore);
        mostraPreOrdem(arvore->direita);
        mostraPreOrdem(arvore->esquerda);
    }
}
void mostraPosOrdem(Node *arvore){ //comeca pelo do canto inferior esquerdo e termina no do canto direito
    if(arvore != NULL){
        mostraPreOrdem(arvore->esquerda);        
        mostraPreOrdem(arvore->direita);
        imprimeDados(arvore);

    }
}

void mostraSimetrica(Node *arvore){
    if(arvore != NULL){
        mostraPreOrdem(arvore->esquerda);          
        imprimeDados(arvore);
        mostraPreOrdem(arvore->direita);

    }

}

void imprimeDados(Node *arvore){
    printf("Nó central: %d\n Ponteiro SE:%p\n Ponteiro SD:%p\n\n", arvore->central, arvore->esquerda, arvore->direita);
}