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

Graph *createGraph(int numVertex);
Vertex *createVertex(int value);
void printGraph(Graph* graph);
void addConnections(Graph *graph, int s, int d, int cost);
void resetVisits(Graph *graph);

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
        newGraph->visited[i] = -1;
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
    while (temp) {
      if (temp->next == NULL){
        printf(" (%d -> %d) weight: %d", v, temp->value, temp->cost);
      }
      else{
        printf(" (%d -> %d) weight: %d |", v, temp->value, temp->cost);
      }
      temp = temp->next;
    }
    printf("\n");
  }
}

void resetVisits(Graph *graph){
  for (int i = 0; i < numNodes; i++){
    graph->visited[i] = 0;
  }
}