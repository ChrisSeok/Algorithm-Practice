#include <iostream>
using namespace std;
void GiveChange(int C){
    int num=C;
    int left;
   for(int i=500;i>=100;i=i/5){
    	int a=num/i; //a=3
		left=num%i;  //left=50
    	cout<<i<<"원:" <<a<<"개" ;
    	if(left==0) break;
    	num=left;
	}// num=50, 
	if(left){
		for(int i=50;i>=10;i=i/5){
		int b=num/i;
		left=num%i;
    	cout<<i<<"원:" <<b<<"개" ;
    	if(left==0) break;
    	num=left;
		}
	}

}

int main(){
	int change;
	cin>>change;
	cout<<"-------------"<<endl<<">>거스름돈:"<<endl; 
	GiveChange(change);
	
	 
} 
