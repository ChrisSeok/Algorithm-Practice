#include <iostream>
using namespace std;
int main(){
	int C;
	cin>>C; //1370
	cout<<"-------------"<<endl<<">>거스름돈:"<<endl; 
    while(1){
	    int a=C/500; //2
	    int b=C%500; //370
	    cout<<"500원:"<<a<<"개 ";
	    int c=C%500/100; //3
		int d=b%100; //70
		cout<<"100원:"<<c<<"개 ";
	    int e=d/50; //1
		int f=d%50; //20
		cout<<"50원:"<<e<<"개 ";
		int g=f/10; //2
		int h=f%10; //0
		cout<<"10원:"<<g<<"개 ";
		break;
	 
} 
}
