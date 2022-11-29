#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <stdbool.h>
#include "queue.h"
#include "graph.h"
#include "kruskal.h"
#include "djistrika.h"
#include "searchs.h"

#define numNodes 9

int main(){
  Edge *conectionList;
  Graph* graph = createGraph(numNodes);
  Graph* kruskalTree = createGraph(numNodes);

  printf("Creating graph...\n");
  
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

  printf("\nGraph created!\n");

  printf("\nDjistrika:\n");

  djistrikaPath(0, graph, 7);

  conectionList = createEdgeList(graph);
  kruskal(conectionList, kruskalTree);

  printf("\nKruskal Algorithm:\n");

  printGraph(kruskalTree);

  printf("\nDFS:\n");

  DFS(graph, 0);

  printf("\nResetting visits...\n");

  resetVisits(graph);

  printf("\nVisits resetted!\n");

  printf("\nBFS:\n");

  BFS(graph, 0);

  return 0;
}