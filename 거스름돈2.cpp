#include <iostream>
using namespace std;
void GiveChange(int C){
    int num=C;
    int left;
   for(int i=500;i>=100;i=i/5){
    	int a=num/i; //a=3
		left=num%i;  //left=50
    	cout<<i<<"¿ø:" <<a<<"°³" ;
    	if(left==0) break;
    	num=left;
	}// num=50, 
	if(left){
		for(int i=50;i>=10;i=i/5){
		int b=num/i;
		left=num%i;
    	cout<<i<<"¿ø:" <<b<<"°³" ;
    	if(left==0) break;
    	num=left;
		}
	}

}

int main(){
	int change;
	cin>>change;
	cout<<"-------------"<<endl<<">>°Å½º¸§µ·:"<<endl; 
	GiveChange(change);
	
	 
} 
