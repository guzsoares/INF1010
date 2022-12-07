#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <stdbool.h>
#define numNodes 9

void DFS( Graph* graph, int vertex);
void BFS(Graph *graph, int src);

void DFS( Graph* graph, int src) {
  Vertex* temp = graph->adjList[src];

  graph->visited[src] = 1;
  printf("Visited:%d\n", src);

  while (temp != NULL) {
    int connectedVertex = temp->value;

    if (graph->visited[connectedVertex] <= 0) {
      DFS(graph, connectedVertex);
    }
    temp = temp->next;
  }
}

void BFS(Graph *graph, int src) {
  
    Queue *q = createQueue();

    graph->visited[src] = 1;
    enqueue(q, src);

    while(!isEmpty(q)) {
      printQueue(q);
      int curr = dequeue(q);
      printf("Visited: %d\n", curr);

      Vertex *temp = graph->adjList[curr];

      while(temp){
        int adjVertex = temp->value;

        if (graph->visited[adjVertex] == 0) {
          graph->visited[adjVertex] = 1;
          enqueue(q, adjVertex);
        }
        temp = temp->next;
      }
    }


}