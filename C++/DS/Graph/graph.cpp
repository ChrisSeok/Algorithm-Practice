#include <iostream>
#include <list>
using namespace std;
class Graph{
    int V; //number of vertex
    list<int> *l; // array of list, but we don't know the size(=V) yet so make it a pointer to the list 
public:
    Graph(int V){
        this->V = V;
        l = new list<int>[V]; // list size 정하는 방법!
        //l is a pointer to an Array of lists! Muyaho~^^
    }
    void addEdge(int v1, int v2){
        l[v1].push_back(v2);
        l[v2].push_back(v1);
    }//Undirected graph

    void printAdjlist(){
        for(int i=0;i<V;i++){
            cout<<"Vertex "<<i<<":";
            for(int x : l[i]){
                cout<<x<<",";
                // if(&(x+1)!=NULL) cout<<",";
            }
            cout<<endl;
        }
    }
};
int main(){
    Graph G(4);
    G.addEdge(0,1);
    G.addEdge(1,3);
    G.printAdjlist();
}
