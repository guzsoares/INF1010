#include <stdlib.h>
#include <stdio.h>

typedef struct vertex{
    int value;
    struct vertex *next;
}Vertex;

typedef struct graph{
    int num_vertex;
    Vertex **adjList;
}Graph;


Vertex *createVertex(int value){
    Vertex *newVertex = malloc(sizeof(Vertex));
    newVertex->value = value;
    newVertex->next = NULL;
    return newVertex;
}

Graph *createGraph(int numVertex){
    Graph *newGraph = malloc(sizeof(Graph));
    newGraph->num_vertex = numVertex;

    newGraph->adjList = malloc(numVertex * sizeof(Vertex));

    for (int i = 0; i < numVertex; i++){
        newGraph->adjList[i] = NULL;
    }
    return newGraph;
}

void addConnections(Graph *graph, int s, int d){
    Vertex *newVertex = createVertex(d);
    newVertex->next = graph->adjList[s];
    graph->adjList[s] = newVertex;

    newVertex = createVertex(s);
    newVertex->next = graph->adjList[d];
    graph->adjList[d] = newVertex;
}

void printGraph(Graph* graph) {
  int v;
  for (v = 0; v < graph->num_vertex; v++) {
    Vertex* temp = graph->adjList[v];
    printf("\n Vertex %d: ", v);
    while (temp) {
      if (temp->next == NULL){
        printf("%d ", temp->value);
      }
      else{
        printf("%d -> ", temp->value);
      }
      temp = temp->next;
    }
    printf("\n");
  }
}   

int main() {
  Graph* graph = createGraph(9);
  addConnections(graph, 0, 1);
  addConnections(graph, 0, 2);
  addConnections(graph, 0, 3);
  addConnections(graph, 1, 4);
  addConnections(graph, 4, 3);
  addConnections(graph, 4, 6);
  addConnections(graph, 3, 6);
  addConnections(graph, 3, 5);
  addConnections(graph, 5, 2);
  addConnections(graph, 2, 8);
  addConnections(graph, 5, 6);
  addConnections(graph, 6, 7);
  addConnections(graph, 7, 8);

  printGraph(graph);

  return 0;
}