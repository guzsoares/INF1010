#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

#define numNodes 9



typedef struct vertex{
    int value;
    int cost;
    struct vertex *next;
}Vertex;

typedef struct graph{
    int num_vertex;
    int *visited;
    Vertex **adjList;
}Graph;

typedef struct Edge{
  int src;
  int dest;
  int cost;
  struct Edge *next;
}Edge;
Edge *createEdgeList(Graph *grafo);
Edge* insertEdge(Edge* conectionList, int src, int dest, int cost);
Edge* createEdge(int src, int dest, int cost);
Graph *createGraph(int numVertex);
Vertex *createVertex(int value);
void printGraph(Graph* graph);
void addConnections(Graph *graph, int s, int d, int cost);
void kruskal(Edge* conectionList, Graph *kruskalTree);
void djistrikaPath(int startNode, Graph *graph, int endNode);
void Union(int vRep[], int x, int y);
void DFS( Graph* graph, int vertex);
void sentNegative(int *vRep, int numVertice);
int find(int vRep[], int i);
int minDistance(int *dist, bool *isPath);


int main(){
  Edge *conectionList;
  Graph* graph = createGraph(numNodes);
  Graph* kruskalTree = createGraph(numNodes);
  
  addConnections(graph, 0, 1, 6);
  addConnections(graph, 0, 2, 9);
  addConnections(graph, 0, 3, 15);
  addConnections(graph, 1, 4, 20);
  addConnections(graph, 4, 3, 4);
  addConnections(graph, 4, 6, 24);
  addConnections(graph, 3, 6, 7);
  addConnections(graph, 3, 5, 10);
  addConnections(graph, 5, 2, 13);
  addConnections(graph, 2, 8, 28);
  addConnections(graph, 5, 6, 5);
  addConnections(graph, 6, 7, 15);
  addConnections(graph, 7, 8, 17);

  djistrikaPath(0, graph, 7);

  conectionList = createEdgeList(graph);
  kruskal(conectionList, kruskalTree);

  printGraph(kruskalTree);

  DFS(graph, 0);

  return 0;
}

Vertex *createVertex(int value){
    Vertex *newVertex = malloc(sizeof(Vertex));
    newVertex->value = value;
    newVertex->cost = 0;
    newVertex->next = NULL;
    return newVertex;
}

Graph *createGraph(int numVertex){
    Graph *newGraph = malloc(sizeof(Graph));

    newGraph->num_vertex = numVertex;
    newGraph->adjList = malloc(numVertex * sizeof(Vertex));
    newGraph->visited = malloc(numVertex * sizeof(int));

    for (int i = 0; i < numVertex; i++){
        newGraph->adjList[i] = NULL;
        newGraph->visited[i] = 0;
    }
    return newGraph;
}

void addConnections(Graph *graph, int s, int d, int cost){
    Vertex *newVertex = createVertex(d);
    newVertex->next = graph->adjList[s];
    newVertex->cost = cost;
    graph->adjList[s] = newVertex;

    newVertex = createVertex(s);
    newVertex->next = graph->adjList[d];
    newVertex->cost = cost;
    graph->adjList[d] = newVertex;
}

void printGraph(Graph* graph) {
  int v;
  for (v = 0; v < graph->num_vertex; v++) {
    Vertex* temp = graph->adjList[v];
    printf("\n Vertex %d: ", v);
    while (temp) {
      if (temp->next == NULL){
        printf(" %d com custo %d", temp->value, temp->cost);
      }
      else{
        printf(" %d com custo %d |", temp->value, temp->cost);
      }
      temp = temp->next;
    }
    printf("\n");
  }
}

int minDistance(int *dist, bool *isPath){
  int min = INT_MAX;
  int min_index;

  for (int i = 0; i < numNodes; i++){
    if (isPath[i] == false && dist[i] <= min){
      min = dist[i];
      min_index = i;
    }
  }

  return min_index;
}

void djistrikaPath(int startNode, Graph *graph, int endNode){
  int dist[numNodes];

  bool isPath[numNodes];

  for (int i = 0; i < numNodes; i++){
    dist[i] = INT_MAX;
    isPath[i] = false;
  }

  dist[startNode] = 0;
  
  for (int j = 0; j < numNodes - 1; j++){
    int aux = minDistance(dist, isPath);

    isPath[aux] = true;

    for (int k = 0; k < numNodes; k++){

      Vertex *temp = graph->adjList[aux];
      while(temp){
        if ((dist[aux] + temp->cost < dist[k]) && temp->value == k){
            dist[k] =  dist[aux] + temp->cost;
        }
        temp = temp->next;
      }

    }
  }
  printf("The shortest path between the starting node %d and the ending node %d is %d\n", startNode, endNode, dist[endNode]);
}

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

void DFS( Graph* graph, int vertex) {
  Vertex* adjList = graph->adjList[vertex];
  Vertex* temp = adjList;

  graph->visited[vertex] = 1;
  printf("Visited:%d\n", vertex);

  while (temp != NULL) {
    int connectedVertex = temp->value;

    if (graph->visited[connectedVertex] == 0) {
      DFS(graph, connectedVertex);
    }
    temp = temp->next;
  }
}