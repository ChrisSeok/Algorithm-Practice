#include <iostream>
#include <windows.h>
using namespace std;
//template <class T>

//Todo:figure out isFull(). 
class Stack {
private:
    int top, curr;
    int MaxSize;
    int *stack;//array  T
public:
    Stack(int size);
    bool isFull(), isEmpty();
    void pop();
    void push(char element);
    void print();
};

Stack::Stack(int size){ //Initializer
    this->stack = new int[size];
    this->MaxSize=size-1;
    this->curr=MaxSize;
    for(int i=0;i<size;i++){ //배열 초기화 시 쓰레기값(not '\0')저장된다. isFull함수를 위해 널문자를  저장해준다. 
    	stack[i]='\0';
	}
}
void Stack::push(char element){
    if(isFull()) { cout<<"Stack is Full. Cannot Push."<<endl;} //주석처리하니 제대로 출력. 
    else {
    stack[curr]=element;
    top=curr;
    --curr;
  }
}
void Stack::pop(){
	if(isEmpty()) cout<<"Empty stack, Cannot pop."<<endl;
    else{
    cout<<"Pop: "<<stack[top]<<endl;
	stack[top]='\0';
    curr++;
    top++;
	}
}
void Stack::print(){
	if(isEmpty()){
		cout<<"Empty stack, Cannot print.";
	}
	else{
	int i=top;
	cout<<"From top"<<endl;
	while(stack[i]!='\0'){
		cout<<stack[i]<<endl;
		i++;
	}
    cout<<endl;
	}
}

bool Stack::isFull(){
	 
    return (stack[0]!='\0') ? true : false;  
}
bool Stack::isEmpty(){
	
    return  (stack[MaxSize]=='\0') ? true : false;
}


int main(){
    Stack s(8);
    for(int i=0;i<7;i++){
        s.push(i+1);
    }
    s.print();
    for(int i=0;i<8;i++){
    s.pop();
	Sleep(1000);
}
    s.print();
   
}
