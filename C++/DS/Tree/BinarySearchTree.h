#ifndef _BinarySearch_Tree_
#define _BinarySearch_Tree_
#include "BinaryTree.h"

void BSTinit(Node **root);
int BSTGetdata(Node *bst);
void BSTinsert(Node **root,int data);
int BSTremove(Node **root,int target);
Node *BSTsearch(Node *bst,int target);

Node *RemoveLeftsubtree(Node *t){ //t의 leftchild를 삭제함
    Node *delNode; 
    if(t!=NULL){
        delNode = t->left; //t->left(포인터)가 저장하는 노드의 주소값을 delNode에 복사
        t->left = NULL; //t->left가 저장하는 노드의 주소값을 NULL로 바꿈. 
    } 
    //so t의 leftchild가 가리키던 노드 자체는 메모리에 남아있음.완전히 삭제하진 않음.
    return delNode; //delNode도 null로 초기화 해주어야 하는거 아닌가? t가 null일 경우 쓰레기 주소값이 리턴되는데..
}

Node *RemoveRightsubtree(Node *t){
    Node *delNode;
    if(t!=NULL){
        delNode = t->right; 
        t->right = NULL; 
    }
    return delNode;
}
void ChangeLeftsubtree(Node *main, Node *sub){
    main->left = sub;
}
void ChangeRightsubtree(Node *main, Node *sub){
    main->right = sub;
}

#endif