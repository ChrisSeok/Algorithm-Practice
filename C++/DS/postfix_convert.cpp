#include <iostream>
#include <cctype>
#include <cstring>
#include <stack>
using namespace std;
//한자릿수만 가능한 postfix 변환 
char OPERATOR[]="+-*/()";
int icp(char op){
    switch(op){
        case '-': return 2;
        case '+': return 2;
        case '/': return 3;
        case '*': return 3;
        case '(': return 9;
    }
    return 0;
}
int isp(char op){
    if(op=='(') return 1;
    else return icp(op);
}

void Convert_Postfix(char expr[]){
    stack <char> Operator;
    int len = strlen(expr);
    int i=0;
    while(i<len){
        if((expr[i]-'0')>0 && (expr[i]-'0')<=9){//피연산자
			cout<<expr[i];
			}
        else{ //연산자
            if(Operator.empty()){ //처음
			Operator.push(expr[i]);
			}
            else{
                if(expr[i]==')'){
                    while(Operator.top()!='('){
                        cout<<Operator.top();Operator.pop();
                    }
                    Operator.pop(); // '(' pop
                }
                else if(icp(expr[i])<=isp(Operator.top())){//들어오는 애보다 top의우선순위 크면 pop
				cout<<Operator.top();Operator.pop();
				}
                else{
				Operator.push(expr[i]);
				}
            }
        }
        i++;
    }
    while(!Operator.empty()){
    cout<<Operator.top(); Operator.pop();
	}
}
int main(){
    char expr[]="2*(3+7)";
    Convert_Postfix(expr);
}