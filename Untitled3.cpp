#include <iostream>
using namespace std;
int totalamount;   //전역변수 선언!! 
   int GetChange(int coin){ //인자로 totalamount 넣으면 안되는 이유: 
   //                          함수의 인자로 쓰는 순간 전역과 다른, 이름만 같은  새로운 변수가 되어버림 
	int j=0;
	for(int i=1;i<=totalamount;i++){
   	if(i%coin==0) j++;	
	}
	cout<<coin<<"원:"<<j<<"개"; 
    totalamount-=j*coin;
} 


int main(){
	int change;//totalamount;
	cin>>change;
	totalamount=change;
	cout<<"-------------"<<endl<<">>거스름돈:"<<endl; 
	GetChange(500);
	//int a= GetChange(500);
	GetChange(100);
	GetChange(50);
	GetChange(10);
	
	
	 
} 
