#include <iostream>
using namespace std;
int main(){
	int C;
	cin>>C; //1370
	cout<<"-------------"<<endl<<">>�Ž�����:"<<endl; 
    while(1){
	    int a=C/500; //2
	    int b=C%500; //370
	    cout<<"500��:"<<a<<"�� ";
	    int c=C%500/100; //3
		int d=b%100; //70
		cout<<"100��:"<<c<<"�� ";
	    int e=d/50; //1
		int f=d%50; //20
		cout<<"50��:"<<e<<"�� ";
		int g=f/10; //2
		int h=f%10; //0
		cout<<"10��:"<<g<<"�� ";
		break;
	 
} 
}
