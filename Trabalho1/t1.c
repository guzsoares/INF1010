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

/* struct lista */

struct lista{
  int tipo;
  void *info;
  struct lista *prox;  
    
};
typedef struct lista Lista;

/* calcular as áreas */

float areaRetang(Retangulo *r);
float areaTriang(Triangulo *t);
float areaCirc(Circulo *c);
float areaHexa(Hexagono *h);
float areaQuad(Quadrado *q);
float calculaArea(Lista *dados);

/* calcular perimetro */

float perimRetang(Retangulo *r);
float perimTriang(Triangulo *t);
float perimCirc(Circulo *c);
float perimHexa(Hexagono *h);
float perimQuad(Quadrado *q);
float calculaPerim(Lista *dados);

/* cria as formas nas listas */

Lista* criaRetangulo(float b, float h, Lista* dados);
Lista* criaCirculo(float r, Lista* dados);
Lista* criaTriangulo(float b, Lista *dados);
Lista* criaHexagono(float b, Lista* dados);
Lista* criaQuadrado(float b, Lista *dados);

/* manipulacao de lista */

void imprimeDados(Lista* dado);
void retiraLista(Lista* dados, Lista *retira);
void freeLista(Lista* dados);

/* metodos para serem utilizados */

void imprimeFigura (Lista* dados, int tipo); // primeiro parametro: lista de dados a ser acessada. segundo parametro: tipo de forma a ser impressa
Lista* buscaTriangulo (Lista* dados, int index); // primeiro parametro: lista de dados a ser acessada. segundo parametro: posição do triangulo a ser buscada. retorno: triangulo buscado.
void retiraLista(Lista* dados, Lista *retira); // primeiro parametro: lista de dados a ser acessada. segundo parametro: informação a ser retirada
void freeLista(Lista* dados); // primeiro parametro: lista de dados para ser liberada da memoria;

/* main */

int main (int argc, char **argv){
    Lista *dados = NULL;
    dados = criaTriangulo(3.0, dados);
    dados = criaQuadrado(2.0, dados);
    dados = criaRetangulo(3.0, 5.0, dados);
    dados = criaTriangulo(5.0, dados);
    dados = criaCirculo(4.0, dados);
    dados = criaHexagono(3.0, dados);
    dados = criaTriangulo(4.0, dados);

    puts("Lista inicial:\n");

    imprimeFigura(dados, TRI); // Primeira impressão

    puts("");

    Lista * retira = buscaTriangulo(dados, 3);  // buscando o segundo triangulo na lista dados e salvando em retira

    retiraLista(dados, retira);  // retirando o valor retira da lista dados

    imprimeFigura(dados, TRI); // imprimindo

    
    return 0;
}

// FUNÇÕES

float areaRetang(Retangulo *r){
    return(r->b*r->h);
}
float areaTriang(Triangulo *t){
    float area = (sqrt(3)/4)*pow(t->b,2);
    return (area);
}
float areaCirc(Circulo *c){
    float area = M_PI*pow(c->r,2);
    return area;
}
float areaHexa(Hexagono *h){
    float area = (3*sqrt(3)*pow(h->b,2))/2;
    return area;
}
float areaQuad(Quadrado *q){
    return (q->b * q->b);
}

float calculaArea(Lista *dados){
    float area;

    switch (dados->tipo){
        case QUA:
            area  = areaQuad((Quadrado*)dados->info);
            break;

        case TRI:
            area  = areaTriang((Triangulo*)dados->info);        
            break;

        case HEX:
            area  = areaHexa((Hexagono*)dados->info);
            break;

        case RET:
            area  = areaRetang((Retangulo*)dados->info);
            break;          

        case CIR:
            area  = areaCirc((Circulo*)dados->info);
            break;

        default:
            printf("Tipo inexistente");
            break;  
    }

    return area;
}

float perimRetang(Retangulo *r){
    return (r->b *2 + r->h *2);
}
float perimTriang(Triangulo *t){
    return (t->b * 3);
}
float perimCirc(Circulo *c){
    return (c->r * 2 * M_PI);
}
float perimHexa(Hexagono *h){
    return (h->b * 6);
}
float perimQuad(Quadrado *q){
    return (q->b * 4);
}

float calculaPerim(Lista *dados){
    float perim;

    switch (dados->tipo){
        case QUA:
            perim  = perimQuad((Quadrado*)dados->info);
            break;

        case TRI:
            perim  = perimTriang((Triangulo*)dados->info);        
            break;

        case HEX:
            perim  = perimHexa((Hexagono*)dados->info);
            break;

        case RET:
            perim  = perimRetang((Retangulo*)dados->info);
            break;          

        case CIR:
            perim  = perimCirc((Circulo*)dados->info);
            break;

        default:
            printf("Tipo inexistente");
            break;  
    }

    return perim;
}

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

Lista* criaTriangulo(float b, Lista *dados){
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

    dados->prox = criaTriangulo(b, dados->prox);


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

void imprimeDados(Lista* dado){
    Lista *aux = dado;

    switch (aux->tipo){
        case QUA:
            printf("Quadrado de area: %.2f e de perimetro: %.2f  \n",calculaArea(aux), calculaPerim(aux));
            break;
        case TRI:
            printf("Triangulo de area: %.2f e de perimetro: %.2f  \n", calculaArea(aux), calculaPerim(aux));      
            break;
        case HEX:
            printf("Hexagono de area: %.2f e de perimetro: %.2f \n",calculaArea(aux), calculaPerim(aux)); 
            break;
        case RET:
            printf("Retangulo de area: %.2f e de perimetro: %.2f  \n",calculaArea(aux), calculaPerim(aux));           
            break;
        case CIR:
            printf("Circulo de area: %.2f e de perimetro: %.2f  \n", calculaArea(aux), calculaPerim(aux));           
            break;
        default:
            printf("Tipo inexistente");
            break;  
        }
}

Lista* buscaTriangulo (Lista* dados, int index){ 
    int count = 1;
    for (Lista *aux=dados; aux!=NULL; aux = aux->prox) {
        if (aux->tipo == TRI && index == count){
            return aux;
        }
        else if (aux->tipo == TRI){
            count++;
        }
        

    }
    return NULL; /* não achou o elemento */
}

void imprimeFigura (Lista* dados, int tipo){ 
    for (Lista *aux = dados; aux != NULL; aux = aux->prox) {
        if (tipo == aux->tipo){
            imprimeDados(aux);
        }
    }
}

void retiraLista(Lista* dados, Lista *retira) {
    Lista * anterior = dados;

    if (dados == retira){
        dados = retira->prox;
    }
    else {
        for(anterior=dados; anterior!=NULL; anterior = anterior->prox) {
            if (anterior->prox == retira){
                break;
            }
        }
        anterior->prox = retira->prox;
    }

    free(retira->info);
    free(retira);

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