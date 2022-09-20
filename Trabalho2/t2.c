#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int central;
    struct node *direita;
    struct node *esquerda;
}Node;

Node *insereABB(int valor, Node *arvore);
Node* retiraABB(Node* r, int chave);
Node *criaArvoreExemplo(int valor, Node *arvore, int isRight);
Node *criaAB(int chave);
int alturaArvore(Node * root);
int isBinaryLogic(Node *arvore);
int buscaABB(Node *arvore, int chave, int nivel);
int buscaAB(Node* arvore, int chave);
void insereAB(Node *pai, Node *filho);
void printAltura(Node * root, int level);
void printArvoreNivel(Node * root);
void isBinary(Node *arvore);
void mostraPreOrdem(Node *arvore);
void mostraPosOrdem(Node *arvore);



int main(void){
    Node *abb = NULL;
    Node *exemplo = NULL;

    //questao 1
    exemplo = criaArvoreExemplo(10, exemplo, 0);
    exemplo = criaArvoreExemplo(5, exemplo, 0);
    exemplo = criaArvoreExemplo(13, exemplo, 1);
    exemplo = criaArvoreExemplo(15, exemplo, 1);
    exemplo = criaArvoreExemplo(7, exemplo, 0);
    exemplo = criaArvoreExemplo(1, exemplo, 0);

    //questao 2
    abb = insereABB(10, abb);
    abb = insereABB(5, abb);
    abb = insereABB(7, abb);
    abb = insereABB(1, abb);
    abb = insereABB(13, abb);
    abb = insereABB(15, abb);


    printf("questao 4\n");
    puts("");
    printf("Arvore 1 em nível\n");

    printArvoreNivel(exemplo);

    printf("Arvore 2 em nível\n");

    printArvoreNivel(abb);

    printf("questao 5\n");
    puts("");
    isBinary(exemplo);
    isBinary(abb);

    printf("questao 6\n");
    puts("");
    int x = alturaArvore(exemplo);
    printf("%d\n",x);

    printf("questao 8\n");
    puts("");
    abb = retiraABB(abb, 1);
    printf("Primeira exclusão\n");

    printArvoreNivel(abb);

    abb = retiraABB(abb, 13);
    printf("Segunda exclusão\n");

    printArvoreNivel(abb);

    abb = retiraABB(abb, 10);
    printf("Terceira exclusão\n");

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

Node *criaArvoreExemplo(int valor, Node *arvore, int isRight){
    Node *aux;
    if(arvore == NULL){
        aux =(Node*)malloc(sizeof(Node)); //inicializa a arvore
        aux->direita = NULL;
        aux->esquerda = NULL;
        aux->central = valor; //primeiro valor
        arvore = aux; //inicializa a arvore, para continuar o loop
    } else {
        if (isRight == 1){
        arvore->direita = criaArvoreExemplo(valor, arvore->direita, 0);
        }
        else {
        arvore->esquerda = criaArvoreExemplo(valor, arvore->esquerda, 1);
        }
    }

    return arvore;
}

//Essa funcao retira um no escolhido de maneira recursiva (ABB)
Node* retiraABB(Node* r, int chave){
    if (r == NULL)
        return NULL;
    else if (r->central > chave)
        r->esquerda = retiraABB(r->esquerda, chave);
    else if (r->central < chave)
        r->direita = retiraABB(r->direita, chave);
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
            f->central = chave;
            r->esquerda = retiraABB(r->esquerda,chave);
        }
    }
    return r;
}
//Essa funcao conecta uma subarvore(filho) a arvore, de maneira arbitraria
void insereAB(Node *pai, Node *filho){
    filho->direita = pai->esquerda;
    pai->esquerda = filho;
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
        printf("%d ", root->central);
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

int buscaABB(Node *arvore, int chave, int nivel){
    int esquerda, direita;

    if(arvore == NULL){
        printf("Arvore vazia");
        return 0;   
    }
    if(arvore->central == chave){
        printf("Chave: %d\nPonteiro SE:%p\nPonteiro SD", arvore->central, arvore->esquerda, arvore->direita);
        return 1;
    }
    if(arvore->central > chave){

        direita = buscaABB(arvore->direita, chave, nivel++);
    }else if(arvore->central < chave){
        esquerda = buscaABB(arvore->esquerda, chave, nivel++);
    }
}

int buscaAB(Node* arvore, int chave){
    if(arvore==NULL){
        printf("Arvore vazia");
        return 0;
    }else if(arvore->central == chave){
        printf("Chave: %d\nPonteiro SE:%p\nPonteiro SD", arvore->central, arvore->esquerda, arvore->direita);
        return 1;
    }else{
        buscaAB(arvore->direita, chave);
        buscaAB(arvore->esquerda, chave);
    }
}

void mostraPreOrdem(Node *arvore){ //comeca da raiz e printa tudo da esquerda, depois da direita 
    if(arvore != NULL){
        printf("Chave: %d\nPonteiro SE:%p\nPonteiro SD", arvore->central, arvore->esquerda, arvore->direita);
        mostraPreOrdem(arvore->direita);
        mostraPreOrdem(arvore->esquerda);
    }
}
void mostraPosOrdem(Node *arvore){ //comeca pelo do canto inferior esquerdo e termina no do canto direito
    if(arvore != NULL){
        mostraPreOrdem(arvore->esquerda);        
        mostraPreOrdem(arvore->direita);
        printf("Chave: %d\nPonteiro SE:%p\nPonteiro SD", arvore->central, arvore->esquerda, arvore->direita);

    }
}