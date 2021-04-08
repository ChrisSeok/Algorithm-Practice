#include <iostream>
#include <cstring>
using namespace std;
#define MAXSIZE 5
struct Node{
    string key;
    int value;
    Node *next;
    Node(string key,int value){
        this->key = key;
        this->value = value;
    }
};
struct Bucket{
    Node *head=NULL;
    int eachsize=0; //0으로 초기화 시켜줘야 Insert함수에서 조건문 가능
};

class Hashtable{
	
public:
    	Bucket *hashtable;
    	Hashtable(){
    		hashtable=new Bucket[MAXSIZE];
    		
		}
	
int getHashCode(string key){ //get a key and turn it into a Hash code

        int hashcode = 0;
hashcode=123;
//        int len = key.length();
//        char *str;
//        strcpy(str,key.c_str());
//         
//        for(int i=0;i<len;i++){
//            int c=str[i];
//            hashcode+=c;
//        }

        return hashcode;
       
    }
    
    int convertToIndex(int hashcode){ 
        int index = hashcode % MAXSIZE;
         

        return index;
    }

     Node * searchKey(Bucket *arr,string key){ //arr로 연결된 노드들 중 같은 key값이 있는지 search.
        if(arr==NULL) return NULL; //NULL은 포인터형
        else{
            Node *node = arr->head;
            for(int i=0;i<(arr->eachsize);i++){
            if(node->key==key) return node;
            else node=node->next;
            }
        }
        return NULL;
    }

    void Insert(string key, int value){
        int hashcode = getHashCode(key);
        int index = convertToIndex(hashcode);
        Node *newnode = new Node(key,value);
        if(hashtable[index].eachsize==0){ //nothing in the bucket
            hashtable[index].head = newnode;
            hashtable[index].eachsize = 1;
        }
        else{
            Node *node = searchKey(&hashtable[index],key);
            if(node==NULL){
            Node *temp = hashtable[index].head;
            hashtable[index].head = newnode;
            newnode->next = temp;
            hashtable[index].eachsize++;
            }
            else{ //key 중복
                cout<<"key duplicated:"<<key<<endl;
                return;
            }
               
        }
         cout<<"insert success! "<<key<<endl;
    }
    void GetValue(string key){
        int hashcode = getHashCode(key);
        int index = convertToIndex(hashcode);
        Node *node = searchKey(&hashtable[index],key);
        if(node==NULL) cout<<"No value found.";
        else cout<<"found value:"<<node->value<<endl;
    }

   
};

int main(){
    Hashtable *H = new Hashtable();
    Hashtable *J = new Hashtable();
    H->Insert("seok",54); //value는 겹쳐도 되지만 key는 겹치면 안됨! 
    H->Insert("park",54);
    H->Insert("seok",3);
    H->GetValue("seok");
    H->GetValue("park");
    
    J->Insert("seok",100); 
    J->GetValue("seok");
    
}



