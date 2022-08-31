#include <stdio.h>
#include <stdlib.h>

#define QUA 0 
#define TRI 1 
#define HEX 2 
#define RET 3 
#define CIR 4

struct triangulo{
    float b;
    float h;
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

float calculaArea(int tipo){
    float area;

    switch (tipo){
        case 0:
            area = dados->info.b * dados->info->h;
            break;
        case 1:
            break;

        case 2:
            break;
        case 3:
            break;          

        case 4:
            break;
        default:
            printf("surreal");
            break;  
    }

    return area;
}


int main (int argc, char **argv){
    

    return 0;
}




