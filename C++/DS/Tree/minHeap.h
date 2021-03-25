#define __minheap_
#define __minheap_
#define True    1
#define False   0
#define Heaplen     100
struct Heapelem{
    int pr;
    int data;
};

struct Heap{
    int numofdata;
    Heapelem heapArr[Heaplen];
};
void HeapInit(Heap *hp);  //initialize
int Hisempty(Heap *hp);
void Hinsert(Heap *hp,int data,int pr);
int Hdelete(Heap *hp);


#endif