#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <stdbool.h>
#define numNodes 9

typedef struct Edge{
  int src;
  int dest;
  int cost;
  struct Edge *next;
}Edge;

Edge *createEdgeList(Graph *grafo);
Edge* insertEdge(Edge* conectionList, int src, int dest, int cost);
Edge* createEdge(int src, int dest, int cost);
void kruskal(Edge* conectionList, Graph *kruskalTree);
void Union(int vRep[], int x, int y);
void sentNegative(int *vRep, int numVertice);
int find(int vRep[], int i);

void kruskal(Edge* conectionList, Graph *kruskalTree){
  Edge *auxEdge = conectionList;
  int vRep[numNodes];
  int x, y;

  sentNegative(vRep, kruskalTree->num_vertex);

  while(auxEdge){
    x = find(vRep, auxEdge->src);
    y = find(vRep, auxEdge->dest);	

    if (x != y){
      Union(vRep, x, y);
      addConnections(kruskalTree, auxEdge->src, auxEdge->dest, auxEdge->cost);
    }
    auxEdge = auxEdge->next;
  }
}

void sentNegative(int *vRep, int numVertice){
  for(int i = 0; i <numVertice; i++){
    vRep[i] = -1;
  }
}

int find(int vRep[], int i){
  if (vRep[i] == -1){
    return i;
  }
  return find(vRep, vRep[i]);
}

void Union(int vRep[], int x, int y){
  vRep[x] = y;
}

Edge *createEdgeList(Graph *grafo){
  Edge* conectionList = NULL;

  for(int i = 0; i < grafo->num_vertex; i++){
    for(Vertex* aux = grafo->adjList[i]; aux != NULL; aux = aux->next){
      conectionList = insertEdge(conectionList, i, aux->value, aux->cost);
    }
  }
  return conectionList;
}

Edge* insertEdge(Edge* conectionList, int src, int dest, int cost){
  Edge *newEdge = createEdge(src, dest, cost);
  Edge* anterior = NULL;
  Edge* atual = conectionList;

  if(conectionList == NULL){
    return newEdge;
  }

  while(atual != NULL && cost >= atual->cost){
    if(cost == atual->cost && (src == atual->dest && dest == atual->src)){
      free(newEdge);			
      return conectionList;		
    }
    anterior = atual;		
    atual = atual->next;
  }
  newEdge->next = atual;		

  if(anterior == NULL){
    return newEdge;			
  }
  anterior->next = newEdge;	
  
  return conectionList;			
}

Edge* createEdge(int src, int dest, int cost){
  Edge* newEdge = (Edge *) malloc(sizeof(Edge));
  if(newEdge == NULL){
	  printf("Erro ao alocar memoria\n");
	  exit(1);
  }
  newEdge->src = src;		
  newEdge->dest = dest;	
  newEdge->cost = cost;	
  newEdge->next = NULL;	

  return newEdge;
}