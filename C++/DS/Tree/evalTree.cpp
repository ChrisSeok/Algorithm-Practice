#include <iostream>
#include <cctype> //isdigit()함수 
#include <cstring>
#include <stack>
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
void PreorderTraverse(Node *bt,Visit action){
    if(bt){
        action(bt->data);
        PreorderTraverse(bt->left,action);
        PreorderTraverse(bt->right,action);
    }
}
void InorderTraverse(Node *bt,Visit action){
    if(bt!=NULL){
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



Node *MakeExpTree(char expr[]){
    int len = strlen(expr);
    stack <Node*> Stack;
    
    for(int i=0;i<len;i++){
        Node *temp= MakeTreeNode();
        if(isdigit(expr[i])){ //숫자일 경우
            SetData(temp,(expr[i]-'0'));
            Stack.push(temp);
        }
        else{
             SetData(temp,expr[i]);
            Makerightsubtree(temp,Stack.top()); Stack.pop(); //문제 생긴듯.
            Makeleftsubtree(temp,Stack.top()); Stack.pop();
           
            Stack.push(temp);
        }
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
        cout<<n->data; // data: 42 (int 형으로 저장됨)
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
	if(0<=data && data<=9) cout<<data; //숫자일땐 int로 바로 출력
	else cout<<(char)data; //형변환.  이제 연산자 출력됨ㅠ!! 
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
    char expr[]="12*7+"; 
    // cin>>expr;
    Node *node= MakeExpTree(expr);
    cout<<"Infix:";ShowInfixExp(node);
    cout<<endl;
	cout<<"Prefix:";ShowPrefixExp(node);
	cout<<endl;
    cout<<"Postfix:";ShowPostfixExp(node);
    cout<<endl<<"result:"<<Evalexptree(node);
    

}

