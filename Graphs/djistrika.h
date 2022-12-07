#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <stdbool.h>
#define numNodes 9

void djistrikaPath(int startNode, Graph *graph, int endNode);
int minDistance(int *dist, bool *isPath);


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
  printf("The shortest path between the starting node %d and the ending node %d is costing %d\n", startNode, endNode, dist[endNode]);
}
