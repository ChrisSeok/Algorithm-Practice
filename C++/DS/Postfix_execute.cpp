#include <iostream>
#include <stack>
using namespace std;

char OPERATOR[]="+-*/()";
int  PRECEDENCE[]={1,1,2,2,-1,-1};

int is_operator(char op){
    for(int i=0;i<strlen(OPERATOR);i++){
        if(OPERATOR[i]==op) return i;//why i ? -> to use it in precedence()
    }
    return -1; // not an operator// is a parenthesis.
}

int  precedence(char op){//우선순위 return 
    return PRECEDENCE[is_operator(op)];
}


