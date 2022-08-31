#include <stdio.h>
#include <stdlib.h>
#include <math.h>


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


Lista* cria_triangulo(float b, float h){
    Triangulo* trig;
    Lista* curr_data;

    // cria triangulo
    trig = (Triangulo*)malloc(sizeof(Retangulo));
    trig->b = b;
    trig->h = h;

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

float calculaArea(Lista *dados){
    float area;

    switch (dados->tipo){
        case QUA:
            area  = area_ret((Quadrado*)dados->info);
            break;

        case TRI:
            area  = area_ret((Triangulo*)dados->info);        
            break;

        case HEX:
            area  = area_ret((Hexagono*)dados->info);

            break;
        case RET:
            area  = area_ret((Retangulo*)dados->info);
            break;          

        case CIR:
            area  = area_ret((Circulo*)dados->info);
            break;
        default:
            printf("Tipo inexistente");
            break;  
    }

    return area;
}


int main (int argc, char **argv){
    

    return 0;
}




