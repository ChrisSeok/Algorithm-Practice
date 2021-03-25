#include <iostream>
using namespace std;
int ISearch(int arr[],int first,int last,int target){//찾으려는 값 target을 넣으면 그 인덱스를 리턴.
    int s;
    if(first>last|| target<arr[first] || target>arr[last]) return -1;
    s = ((double)(target-arr[first])/(arr[last]-arr[first])*(last-first)+first);
//target=2, s=0
    cout<<"s:"<<s<<endl;
    cout<<"first:"<<first<<' '<<"last:"<<last<<endl;
    if(arr[s]==target) return s;
    else if(target<arr[s]) return ISearch(arr,first,s-1,target);
    else return ISearch(arr,s+1,last,target);

}
int main(){
    int arr[]={1,3,4,5,6,7,11};
    int target=2;
    int idx = ISearch(arr,0,sizeof(arr)/sizeof(int)-1,target);
    if(idx==-1) cout<<"failed searching";
    else cout<<"\'"<<target<<"\'"<<"is stored in index"<<idx;
}