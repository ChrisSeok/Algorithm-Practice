#include <iostream>
using namespace std;
int totalamount;   //�������� ����!! 
   int GetChange(int coin){ //���ڷ� totalamount ������ �ȵǴ� ����: 
   //                          �Լ��� ���ڷ� ���� ���� ������ �ٸ�, �̸��� ����  ���ο� ������ �Ǿ���� 
	int j=0;
	for(int i=1;i<=totalamount;i++){
   	if(i%coin==0) j++;	
	}
	cout<<coin<<"��:"<<j<<"��"; 
    totalamount-=j*coin;
} 


int main(){
	int change;//totalamount;
	cin>>change;
	totalamount=change;
	cout<<"-------------"<<endl<<">>�Ž�����:"<<endl; 
	GetChange(500);
	//int a= GetChange(500);
	GetChange(100);
	GetChange(50);
	GetChange(10);
	
	
	 
} 
