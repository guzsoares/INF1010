#include <stdio.h>
#include <stdlib.h>
#include <math.h>
/*
Funcoes Feitas:
    -Todas as structs
    -Calcula areas
    -Cria figura
    -Verifica tipo e imprime a area da figura x
    -Calcula maior area 
    -Libera lista

Falta fazer:
    -Funcao inicializa lista
    -Funcao imprime lista (TIPO DE FIGURA, DADOS, AREA)

*/

#define QUA 0 
#define TRI 1 
#define HEX 2 
#define RET 3 
#define CIR 4

struct triangulo{
    float b;

};
typedef struct triangulo Triangulo;

struct hexagono{
    float b;
};
typedef struct hexagono Hexagono;

struct retangulo{
    float b;
    float h;
};
typedef struct retangulo Retangulo;

struct circulo{
    float r;
};
typedef struct circulo Circulo;

struct quadrado{
    float b;
};
typedef struct quadrado Quadrado;

struct lista{
  int tipo;
  void *info;
  struct lista *prox;  
    
};
typedef struct lista Lista;

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

Lista* cria_ret(float b, float h){
    Retangulo* ret;
    Lista* curr_data;

    //cria retangulo
    ret = (Retangulo*)malloc(sizeof(Retangulo));

    ret->b = b;
    ret->h = h;

    // cria lista
    curr_data = (Lista*)malloc(sizeof(Lista));

    curr_data->tipo = RET;
    curr_data->info = ret;
    curr_data->prox = NULL;

    return curr_data;
}

Lista* cria_circulo(float r){
    Circulo* circ;
    Lista* curr_data;

    // cria triangulo
    circ = (Circulo*)malloc(sizeof(Circulo));
    circ->r = r;

    // cria lista
    curr_data = (Lista*)malloc(sizeof(Lista));
    curr_data->tipo = CIR;
    curr_data->info = circ;
    curr_data->prox = NULL;

    return curr_data;
}

Lista* cria_triangulo(float b){
    Triangulo* trig;
    Lista* curr_data;

    // cria triangulo
    trig = (Triangulo*)malloc(sizeof(Retangulo));
    trig->b = b;

    // cria lista
    curr_data = (Lista*)malloc(sizeof(Lista));
    curr_data->tipo = TRI;
    curr_data->info = trig;
    curr_data->prox = NULL;

    return curr_data;
}

Lista* cria_hex(float b){
    Hexagono* hex;
    Lista* curr_data;

    // cria triangulo
    hex = (Hexagono*)malloc(sizeof(Hexagono));
    hex->b = b;

    
    // cria lista
    curr_data = (Lista*)malloc(sizeof(Lista));
    curr_data->tipo = HEX;
    curr_data->info = hex;
    curr_data->prox = NULL;

    return curr_data;
}

Lista* cria_quad(float b){
    Quadrado* quad;
    Lista* curr_data;

    // cria triangulo
    quad = (Quadrado*)malloc(sizeof(Quadrado));
    quad->b = b;


    // cria lista
    curr_data = (Lista*)malloc(sizeof(Lista));
    curr_data->tipo = QUA;
    curr_data->info = quad;
    curr_data->prox = NULL;

    return curr_data;
}

float calculaArea(Lista *lst){
    float area;

    switch (lst->tipo){
        case QUA:
            area  = area_quad((Quadrado*)lst->info);
            break;

        case TRI:
            area  = area_trig((Triangulo*)lst->info);        
            break;

        case HEX:
            area  = area_hex((Hexagono*)lst->info);

            break;
        case RET:
            area  = area_ret((Retangulo*)lst->info);
            break;          

        case CIR:
            area  = area_circ((Circulo*)lst->info);
            break;
        default:
            printf("Tipo inexistente");
            break;  
    }

    return area;
}

Lista* lst_busca (Lista* lst, int val){ 
    Lista* aux;
    for (aux=lst; aux!=NULL; aux = aux->prox) {
        if (aux->tipo == val)
        return aux;
    }
    return NULL; /* não achou o elemento */
}
/*
Lista* lst_retira (Lista* lst, int val){
    Lista* ant = NULL; 
    Lista* p = lst; 
    while (p != NULL && p->info != val) {
        ant = p;
        p = p->prox;
    }

    if (p == NULL)
        return lst; 

    if (ant == NULL) /
        lst = p->prox;
    else 
        ant->prox = p->prox;
    
    free(p); 
    return lst;
}
*/

void lst_libera (Lista* lst){
    Lista* aux = lst;
    while (aux != NULL) {
        Lista* t = aux->prox; /* guarda referência para o próximo elemento */
        free(aux); /* libera a memória apontada por p */
        aux = t; /* faz p apontar para o próximo */
    }
}

float maiorArea(Lista *lst){
    float maiorArea = 0.0;
    Lista *aux;
    for(aux = lst; aux!= NULL; aux= aux->prox){
        float area = calculaArea(aux);
        if(area> maiorArea)
            maiorArea = area;
    }

    return maiorArea;
}


void imprimeLista(Lista* lst){
    Lista *atual;
    for(atual = lst; atual !=NULL; atual = atual->prox){
        switch (atual->tipo){
            case QUA:
                printf("Quadrado area %f",calculaArea(atual));
                break;
            case TRI:
                printf("Triangulo de area %f", calculaArea(atual));      
                break;
            case HEX:
                printf("Triangulo area %f",calculaArea(atual)); 
                break;
            case RET:
                printf("Retangulo  area %f",calculaArea(atual));           
                break;
            case CIR:
                printf("Circulo de area %f", calculaArea(atual));           
                break;
            default:
                printf("Tipo inexistente");
                break;  
            }
    }
}


Lista *lst_cria(){
    return NULL;
}
int main (int argc, char **argv){
    Lista *lst;
    lst = lst_cria();
    lst = cria_triangulo(3.0);
    lst = cria_triangulo(3.0);
    lst = cria_triangulo(3.0);
    lst = cria_quad(2.0);
    lst = cria_ret(3.0, 5.0);
    lst = cria_circulo(4.0);
    lst = cria_hex(3.0);

    imprimeLista(lst);
    
    printf("%f",maiorArea(lst));
    
    return 0;
}




