#ifndef __Graph__
#define __Graph__
// #include "LinkedList.h"
#include <list>

//정점의 이름을 상수화 
enum{A,B,C,D,E,F,G,H,I,J};
struct Graph{
    int numV;
    int numE;
    list <int>*adjList;
}
void GraphInit(Graph *gh,int nv);
void GraphDestroy(Graph *gh);
void AddEdge(Graph *gh, int fromV, int toV);
void PrintEdgeInfo(Graph *gh);



#endif  