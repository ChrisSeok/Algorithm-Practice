#include <iostream>
#include <windows.h>
using namespace std;

// template <typename T>
typedef struct Node{
    int data;
    Node *next;
    Node *back;
    Node():data(0),next(nullptr),back(nullptr){};
    Node(int x) : data(x), next(nullptr),back(nullptr) {};
    Node(int x, Node *next, Node *back) : data(x),next(next),back(back) {};
    bool isFull(), isEmpty();
    void pop();
    void push(int element);
    void print();

};

class Stack{
public:
    Node *dummyhead = NULL;
    Node *top = NULL;
    Stack(){
    this->dummyhead = new Node();
    this->top = dummyhead;
    }

void push(int element){
    if(isFull()) { cout<<"Stack is Full. Cannot Push."<<endl;} 
    else {
    Node *newnode = new Node(element);
    top->next=newnode;
    newnode->back=top;
    top=top->next;
  }
}
// template <typename T>
void Stack<T>::pop(){
	if(isEmpty()) cout<<"Empty stack, Cannot pop."<<endl;
    else{
    cout<<"Pop: "<<stack[top]<<endl;
	stack[top]='\0';
    curr++;
    top++;
	}
}
// template <typename T>
void Stack<T>::print(){
	if(isEmpty()){
		cout<<"Empty stack, Cannot print.";
	}
	else{
	int i=top;
	cout<<"From top:"<<endl;
	while(i<=MaxSize){
		cout<<stack[i]<<endl;
		i++;
	}
    cout<<endl;
	}
}
// template <typename T>
bool Stack<T>::isFull(){
	 
    return (stack[0]!='\0') ? true : false ;  
}
// template <typename T>
bool Stack<T>::isEmpty(){
	
    return  (stack[MaxSize]=='\0') ? true : false;
}

};//class

int main(){
   
   
}
