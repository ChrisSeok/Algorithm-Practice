#include <iostream>
#include <windows.h>
using namespace std;

template <typename T>
class Stack {
private:
    int top, curr;
    int MaxSize;
    T *stack;//array of T
public:
    Stack(int size);
    bool isFull(), isEmpty();
    void pop();
    void push(T element);
    void print();
};
template <typename T>
Stack<T>::Stack(int size){ //Initializer
    this->stack = new T [size];
    this->MaxSize=size-1;
    this->curr=MaxSize;
    for(int i=0;i<size;i++){ //배열 초기화 시 쓰레기값(not '\0')저장된다. isFull함수를 위해 널문자를  저장해준다. 
    	stack[i]='\0';
	}
}

template <typename T>
void Stack<T>::push(T element){
    if(isFull()) { cout<<"Stack is Full. Cannot Push."<<endl;} 
    else {
    stack[curr]=element;
    top=curr;
    --curr;
  }
}
template <typename T>
void Stack<T>::pop(){
	if(isEmpty()) cout<<"Empty stack, Cannot pop."<<endl;
    else{
    cout<<"Pop: "<<stack[top]<<endl;
	stack[top]='\0';
    curr++;
    top++;
	}
}
template <typename T>
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
template <typename T>
bool Stack<T>::isFull(){
	 
    return (stack[0]!='\0') ? true : false ;  
}
template <typename T>
bool Stack<T>::isEmpty(){
	
    return  (stack[MaxSize]=='\0') ? true : false;
}


int main(){
    Stack<int> s(8);

    for(int i=0;i<8;i++){
        s.push(i+1);
    }
    s.print();
    for(int i=0;i<7;i++){
    s.pop();
	Sleep(1000);
}
    s.print();
   
}
