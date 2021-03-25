#include <iostream>
#include <list>
#include <cstring>
using namespace std;
class HashTable{
    class Node{
        string key;
        string value;
        Node(string key,string value){
            this.key=key;
            this->value=value;
        }
        string Value(){//value를 가져오는 함수
            return value;
        }
        void Value(string value){ //value 저장
            this->value=value;
        }
    }
public:
    //데이터를 저장할 배열을 L.L로 선언

    list <Node>List;
    list<Node>::iterator iter;

    HashTable(int size){
        this->List = new list[size]; // hashtable만듬과 동시에 고정된 배열 미리 만들기.
    }

    int getHashCode(string key){ //get a key and turn it into a Hash code
        int hashcode = 0;
        for(char c:key.toCharArray()){
            hashcode+=c;
        }
        return hashcode;
    }
    int convertToIndex(int hashcode){ //hashcode를 받아서 배열방의 index로 반환
        int index = hashcode % List.size();
        return index;
    }

    Node searchKey(list<Node>tlist, string key){
        if(tlist==0) return NULL;
        list<Node>::iterator iter;
        
        for(iter=tlist.begin();iter!=tlis.end();iter++){
            if((*iter).key==key){
                return *iter;
            }
        }
        return NULL;
    }
    void put(string key, string value){ //데이터 받아서 저장하는 함수
        int hashcode = getHashCode(key);
        int index = convertToIndex(hashcode);
        list<Node>llist = List[index];
        if(llist==null){
            llist = new list<Node>(); // ()는 생성자.동적할당
            List[index]=llist;
        }
        Node node = searchKey(llist,key);//같은거 있나 찾아봄
        if(node ==NULL){
            List.push_back(new Node(key,value));
        }
        else{ //안비어 있으면 덮어쓰는걸로 중복키 처리
            node.Value(value);
        }
    }
    string get(string key){//key를 가지고 데이터를 가져오는 함수
        int hashcode = getHashCode(key);
        int index = convertToIndex(hashcode);
        list<Node> llist = List[index];
        Node node=searchKey(llist,key);
        return (node==null)?"Not found.":node.Value();
    }

}


int main(){
    HashTable H = new HashTable(3);
    H.put("seok","one");
    H.put("park","two");
    H.put("Lee","three");
    H.put("Foo","four");
    cout<<H.get("seok");

}