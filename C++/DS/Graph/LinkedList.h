#ifndef _Linked_List_H
#define _Linked_List_H
struct Node{
    int data;
    Node *next;
};

struct Linkedlist{
    Node *head;
    Node *cur;
    Node *before;
    int numofData;
    int (*comp)(int d1,int d2);
};



#endif  