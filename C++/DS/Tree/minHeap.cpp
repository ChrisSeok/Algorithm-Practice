#include <iostream>
#include <cctype> //for func isdigit()
#include <cstring>
#include <stack>
#include "TREE.h"
#include "minHeap.h"
using namespace std;
// struct Heapelem{
//     int pr;
//     int data;
// };

// struct Heap{
//     int numofdata;
//     Heapelem heapArr[Heaplen];
// };

void HeapInit(Heap *hp){
    hp->numofdata=0;
}

int Hisempty(Heap *hp){
    if(hp->numofdata==0) return True;
    else return False;
}

int GetParentIndx(int childindx){
    return childindx/2;
}
int GetLeftchildIndx(int pindx){
    return pindx*2;
}
int GetRightchildIndx(int pindx){
    return pindx*2+1;
}

int GetHigherindx(Heap *hp, int pindx){
    int L = GetLeftchildIndx(pindx);
    int R = GetRightchildIndx(pindx);
    if(L==hp->numofdata) return L;
    else if(L>hp->numofdata) return 0;
    else{ //pr과 indx가 어떻게 다른것인가?
        if(hp->heapArr[L].pr > hp->heapArr[R].pr) return L;
        else return R;
    }
}
void Hinsert(Heap *hp,int data,int pr){

}
int Hdelete(Heap *hp);
