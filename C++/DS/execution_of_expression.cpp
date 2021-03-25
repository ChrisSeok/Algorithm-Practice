#include <iostream>
#include <stack>
using namespace std;

char OPERATOR[]="+-";

int is_operator(char op){
    for(int i=0;i<2;i++){
        if(OPERATOR[i]==op) return i; //0,1
    }

    return -1; //if not operator
}

int operation(char op,int opnd1,int opnd2){
    int tmp;
    if(op=='+') return tmp= opnd1+opnd2;
    else return tmp= opnd1-opnd2;
 
}

int execute(char *expr){
    int i=0;
    int opnd1, opnd2;
    stack <int> STACK;
    while(expr[i]){
        if(is_operator(expr[i])<0){
            STACK.push(expr[i]);
        }
        else{
            STACK.push(expr[i+1]);
            opnd2=STACK.top(); STACK.pop();
            opnd1=STACK.top(); STACK.pop();
            STACK.push(operation(expr[i],opnd1,opnd2));

        }
    }
    return STACK.top();
}


int main(){
    char expr[50];
    cin>>expr;
    cout<<expr<<"="<<execute(expr);

}