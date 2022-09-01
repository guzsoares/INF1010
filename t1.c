#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define QUA 0 
#define TRI 1 
#define HEX 2 
#define RET 3 
#define CIR 4

/* structs das formas */

typedef struct triangulo{
    float b;
}Triangulo;

typedef struct hexagono{
    float b;
}Hexagono;

typedef struct retangulo{
    float b;
    float h;
}Retangulo;

struct circulo{
    float r;
};
typedef struct circulo Circulo;

struct quadrado{
    float b;
};
typedef struct quadrado Quadrado;

/* ------------------------------------------------------------------------------------- */

/* struct lista */

struct lista{
  int tipo;
  void *info;
  struct lista *prox;  
    
};
typedef struct lista Lista;

/* --------------------------------------------------------------------------------- */

/* Funcoes para calcular as áreas */

static float area_ret(Retangulo *r){
    return(r->b*r->h);
}
static float area_trig(Triangulo *t){
    float area = (sqrt(3)/4)*pow(t->b,2);
    return (area);
}
static float area_circ(Circulo *c){
    float area = M_PI*pow(c->r,2);
    return area;
}
static float area_hex(Hexagono *h){
    float area = (3*sqrt(3)*pow(h->b,2))/2;
    return area;
}
static float area_quad(Quadrado *q){
    return (q->b * q->b);
}

float calculaArea(Lista *dados){
    float area;

    switch (dados->tipo){
        case QUA:
            area  = area_quad((Quadrado*)dados->info);
            break;

        case TRI:
            area  = area_trig((Triangulo*)dados->info);        
            break;

        case HEX:
            area  = area_hex((Hexagono*)dados->info);
            break;

        case RET:
            area  = area_ret((Retangulo*)dados->info);
            break;          

        case CIR:
            area  = area_circ((Circulo*)dados->info);
            break;

        default:
            printf("Tipo inexistente");
            break;  
    }

    return area;
}

float maiorArea(Lista *dados){
    float maiorArea = 0;
    Lista *aux;
    for(aux = dados; aux != NULL; aux = aux->prox){
        float area = calculaArea(aux);
        if(area > maiorArea)
            maiorArea = area;
    }

    return maiorArea;
}

/* ----------------------------------------------------------------------- */

/* cria as formas nas listas */

Lista* criaRetangulo(float b, float h, Lista* dados){
    Retangulo* ret;
    Lista* curr_data = NULL;


    if (!(dados)) {

        ret = (Retangulo*)malloc(sizeof(Retangulo));
        ret->b = b;
        ret->h = h;

        curr_data = (Lista*)malloc(sizeof(Lista));
        curr_data->tipo = RET;
        curr_data->info = ret;
        curr_data->prox = NULL;
        dados = curr_data;
        return dados;
    }

    dados->prox = criaRetangulo(b, h, dados->prox);


    return dados;
}

Lista* criaCirculo(float r, Lista* dados){
    Circulo* circ;
    Lista* curr_data = NULL;


    if (!(dados)) {

        circ = (Circulo*)malloc(sizeof(Circulo));
        circ->r = r;

        curr_data = (Lista*)malloc(sizeof(Lista));
        curr_data->tipo = CIR;
        curr_data->info = circ;
        curr_data->prox = NULL;
        dados = curr_data;
        return dados;
    }

    dados->prox = criaCirculo(r, dados->prox);


    return dados;
}

Lista* cria_triangulo(float b, Lista *dados){
    Triangulo* trig;
    Lista* curr_data = NULL;


    if (!(dados)) {

        trig = (Triangulo*)malloc(sizeof(Triangulo));
        trig->b = b;

        curr_data = (Lista*)malloc(sizeof(Lista));
        curr_data->tipo = TRI;
        curr_data->info = trig;
        curr_data->prox = NULL;
        dados = curr_data;
        return dados;
    }

    dados->prox = cria_triangulo(b, dados->prox);


    return dados;
}

Lista* criaHexagono(float b, Lista* dados){
    Hexagono* hex;
    Lista* curr_data = NULL;


    if (!(dados)) {

        hex = (Hexagono*)malloc(sizeof(Hexagono));
        hex->b = b;

        curr_data = (Lista*)malloc(sizeof(Lista));
        curr_data->tipo = HEX;
        curr_data->info = hex;
        curr_data->prox = NULL;
        dados = curr_data;
        return dados;
    }

    dados->prox = criaHexagono(b, dados->prox);


    return dados;
}

Lista* criaQuadrado(float b, Lista *dados){
    Quadrado* quad;
    Lista* curr_data = NULL;


    if (!(dados)) {

        quad = (Quadrado*)malloc(sizeof(Quadrado));
        quad->b = b;

        curr_data = (Lista*)malloc(sizeof(Lista));
        curr_data->tipo = QUA;
        curr_data->info = quad;
        curr_data->prox = NULL;
        dados = curr_data;
        return dados;
    }

    dados->prox = criaQuadrado(b, dados->prox);


    return dados;
}

/* ------------------------------------------------------------------------------ */

/* manipulacao de lista */

void imprimeLista(Lista* dados){
    Lista *aux;
    for(aux = dados; aux !=NULL; aux = aux->prox){
        switch (aux->tipo){
            case QUA:
                printf("Quadrado area %.2f \n",calculaArea(aux));
                break;
            case TRI:
                printf("Triangulo de area %.2f \n", calculaArea(aux));      
                break;
            case HEX:
                printf("Hexagono area %.2f \n",calculaArea(aux)); 
                break;
            case RET:
                printf("Retangulo  area %.2f \n",calculaArea(aux));           
                break;
            case CIR:
                printf("Circulo de area %.2f \n", calculaArea(aux));           
                break;
            default:
                printf("Tipo inexistente");
                break;  
            }
    }
}

Lista* buscaForma (Lista* dados, int val){ 
    Lista* aux;
    for (aux=dados; aux!=NULL; aux = aux->prox) {
        if (aux->tipo == val)
        return aux;
    }
    return NULL; /* não achou o elemento */
}

void retiraLista(Lista* dados, int index) {
    Lista* atual = dados;
    Lista* anterior = NULL;
    Lista* prox = dados->prox;
    int count = 0;

    if (index == 0){
        anterior = NULL;
        prox = atual->prox;
        dados = dados->prox;
    }
    else {

        while (count != index) {
            count++;
            anterior = atual;
            atual = prox;
            prox = atual->prox;
        }

        anterior->prox = prox;

    }
    free(atual);
}

void freeLista(Lista* dados){
    Lista* aux = dados;
    while (aux != NULL) {
        Lista* next = aux->prox;
        free(aux->info); // liberando memória da forma
        free(aux);  // liberando posição da lista
        aux = next; // resetando auxiliar
    }
}

/* ----------------------------------------------------------------------------------------------- */

int main (int argc, char **argv){
    Lista *dados = NULL;
    dados = cria_triangulo(3.0, dados);
    dados = cria_triangulo(4.0, dados);
    dados = cria_triangulo(5.0, dados);
    dados = criaQuadrado(2.0, dados);
    dados = criaRetangulo(3.0, 5.0, dados);
    dados = criaCirculo(4.0, dados);
    dados = criaHexagono(3.0, dados);

    imprimeLista(dados);

    printf("Maior área: %.2f\n",maiorArea(dados));

    retiraLista(dados,0);

    puts("");

    imprimeLista(dados);

    
    return 0;
}