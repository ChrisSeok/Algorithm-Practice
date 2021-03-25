#include <iostream>
#include <stack>
#include <cstring>
using namespace std;
#define MAX_LENGTH  50

stack<char> s;
char open[]="([{";
char close[]=")]}";

void is_balanced(char *expr,int len){
	for(int i=0;i<len;i++){
		for(int j=0;j<3;j++){
			if(expr[i]==open[j]){ s.push(expr[i]);
			cout<<"push:"<<s.top()<<endl;
		}
		}
	}
	for(int i=0;i<len;i++){
		for(int j=0;j<3;j++){
			if(expr[i]==close[j]){
				cout<<expr[i]<<endl;
				cout<<s.top()<<endl;
			if(open[j]!=s.top()){
				cout<<"Unbalanced.Not in order."<<endl;
				return;
			}
			s.pop();
			}
		}
	}
	if(!s.empty()) cout<<"Unbalanced.Not properly closed."<<endl;
	else cout<<"Balanced.";
}


int main(){

    char expr[MAX_LENGTH];
    cout<<"expr:";
    cin>>expr;
    cout<<expr<<endl;
	is_balanced(expr,strlen(expr));
    

}