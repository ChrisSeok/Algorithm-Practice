#ifndef __TREE_H_
#define __TREE_H_
#include <iostream>
using namespace std;

struct Node{
    int data;
    struct Node *left;
    struct Node *right;
};
Node *MakeTreeNode(){
    Node *newnode = new Node;
    newnode->left=NULL;
    newnode->right=NULL;
    return newnode;
}

int GetData(Node *n){
    return n->data;
}

void SetData(Node *n, int data){
    n->data = data;
}
Node *Getleftsubtree(Node *n){
    return n->left;
}
Node *Getrightsubtree(Node *n){
    return n->right;
}
void Makeleftsubtree(Node *main, Node *lsub){
    if(main->left!=NULL){
        delete main->left;
        }
    main->left = lsub;
}
void Makerightsubtree(Node *main, Node *rsub){
if(main->right!=NULL){
        delete main->right;
        }
    main->right = rsub;
}

typedef void Visit(int data);

void Showdata(int data){
    cout<<data;
}
void PreorderTraverse(Node *bt,Visit action){
    if(bt){
        action(bt->data);
        PreorderTraverse(bt->left,action);
        PreorderTraverse(bt->right,action);
    }
}
void PreorderTraverse(Node *bt){ //cpp파일에서 호출 편리하게 
  PreorderTraverse(bt,Showdata);
  cout<<endl;
}

void InorderTraverse(Node *bt,Visit action){
    if(bt){
        InorderTraverse(bt->left,action);
        action(bt->data);
        InorderTraverse(bt->right,action);
    }
}
void PostorderTraverse(Node *bt,Visit action){
    if(bt){
        PostorderTraverse(bt->left,action);
        PostorderTraverse(bt->right,action);
        action(bt->data);
    }
}


#endif