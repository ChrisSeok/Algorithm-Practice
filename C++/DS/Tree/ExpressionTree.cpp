#include <iostream>
#include <cctype>
#include <cstring>
#include <stack>
#include "BinaryTree.h"
#include "ExpressionTree.h"
using namespace std;

Node *MakeExpTree(char expr[]){
    int len = strlen(expr);
    stack <Node*> Stack;
    Node *temp;
    for(int i=0;i<len;i++){
        temp= MakeTreeNode();
        if(isdigit(expr[i])){ //숫자일 경우
            SetData(temp,expr[i]-'0');
        }
        else{
            SetData(temp, expr[i]);
            Makerightsubtree(temp,Stack.top()); Stack.pop();
            Makeleftsubtree(temp,Stack.top()); Stack.pop();
            
        }
        Stack.push(temp);
    }
    return Stack.top();
}
int Evalexptree(Node *n){
    if(n->left && n->right){ 
    Evalexptree(n->left);
    if(n->data=='+'){
        int x=(n->left->data) + (n->right->data);
        n->data=x;
    } 
    else if(n->data=='-'){
        int x=(n->left->data) - (n->right->data);
        n->data=x;
    }
    else if(n->data=='*'){
        int x=(n->left->data)*(n->right->data);
        n->data=x;
    }
    else{
        int x=(n->left->data)/(n->right->data);
        n->data=x;
    }
    
    }
    return n->data;

}

void ShowNodeData(int data){
    if(isdigit(data)) cout<<data;
    else cout<<(char)data;  
}
void ShowPrefixExp(Node *bt){
    PreorderTraverse(bt,ShowNodeData);
}
void ShowInfixExp(Node *bt){
    InorderTraverse(bt,ShowNodeData);
}
void ShowPostfixExp(Node *bt){
    PostorderTraverse(bt,ShowNodeData);
}

int main(){
    char expr[]="12+7*"; 
    // cin>>expr;
    Evalexptree(MakeExpTree(expr));

}

