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
    Vertex **adjList;
}Graph;


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

    for (int i = 0; i < numVertex; i++){
        newGraph->adjList[i] = NULL;
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

  printf("The shortest path between the starting node %d and the ending node %d is %d", startNode, endNode, dist[endNode]);
}

int main() {
  Graph* graph = createGraph(numNodes);
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

  return 0;
}