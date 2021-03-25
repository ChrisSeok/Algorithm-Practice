#include <iostream>
#include "BinarySearchTree.h"

int BSTGetdata(Node *bst);//Getdata그냥 쓰면 되니까 구현 안할려

void BSTinit(Node **root){ //why use a double pointer?
    *root = NULL;
}

void BSTinsert(Node **root,int data){
    Node *pNode = NULL; //parent node
    Node *currNode = *root; //current node
    Node *nNode = NULL; //new node

    //새 노드가 추가될 위치를 찾는다. 더이상 비교대상이 없을 때 까지.
    while(currNode != NULL){ 
        if(data == GetData(currNode)){
            cout<<"key overlapping not allowed.";
            return;
        }
        pNode = currNode;
        if(GetData(currNode)>data)//들어오는 데이터가 더 작으면 왼쪽트리로 가야함
            currNode = Getleftsubtree(currNode);
        else
            currNode = Getrightsubtree(currNode);

    } //currNode is where we insert the new data.

    nNode = MakeTreeNode();
    SetData(nNode, data);

    if(pNode==NULL){ //empty Tree
        *root = nNode;
    }
    else{
        if(data<GetData(pNode))
            Makeleftsubtree(pNode,nNode);
        else Makerightsubtree(pNode,nNode);
    }

}

int level;
Node *BSTsearch(Node *root, int target){
    Node *currNode = root;
    int currdata;
    level=0;
    while(currNode!=NULL){
        currdata = GetData(currNode);
        if(target==currdata){
            return currNode;
        }
        else if(target>currdata){
            level++;
            currNode = Getrightsubtree(currNode);
        }
        else{
            level++;
            currNode = Getleftsubtree(currNode);
        }

    }
    return NULL; //target does not exist in this tree.
}


void Search(Node *root, int target){
   Node *sNode= BSTsearch(root,target);
   if(sNode==NULL) cout<<"Failed Search.";
    else{
        cout<<"Found key:"<<GetData(sNode)<<endl<<"level:"<<level<<endl;
    }
}

int BSTremove(Node **root,int target){
    Node *dummyroot = MakeTreeNode();
    Node *pNode = dummyroot;
    Node *cNode = *root;
    Node *dNode;

    ChangeRightsubtree(pNode,*root);

    while(cNode!=NULL &&GetData(cNode)!=target){
        pNode = cNode;//한칸 내려감
        if(target<GetData(cNode)) cNode=Getleftsubtree(cNode);
        else cNode = Getrightsubtree(cNode);
    }
    if(cNode == NULL) return 0; // 삭제 대상 존재X
    
    dNode = cNode;
    int deldata = GetData(dNode);

    //1.삭제대상이 단말노드인 경우
    if(Getleftsubtree(dNode)==NULL && Getrightsubtree(dNode)==NULL ){
        if(dNode==Getleftsubtree(pNode)) RemoveLeftsubtree(pNode);//pnode의 left는 NULL이 되고 삭제될 노드의 주소가 리턴됨
        else RemoveRightsubtree(pNode);

    }
    //2.삭제대상이 하나의 자식노드만 가진 경우
    else if (Getleftsubtree(dNode)==NULL || Getrightsubtree(dNode)==NULL){
        Node *childNode;
        if(Getleftsubtree(dNode)!=NULL){//삭제대상인 dNode에게 leftchild만 있을 때: leftchild를 childnode에 저장하고 childnode를 pnode의 자식으로 만든다. dnode가 pnode의 왼쪽자식인지 오른쪽자식인지 여부 확인 후.
            childNode = Getleftsubtree(dNode);
        }
        else childNode = Getrightsubtree(dNode);

        if(dNode==Getleftsubtree(pNode)){//dNode가 pNode의 왼쪽자식인 경우: childNode를 pNode의 왼쪽자식으로 편입
        ChangeLeftsubtree(pNode,childNode);
        }
        else ChangeRightsubtree(pNode,childNode);
    }

    //3. 삭제대상이 두개의 자식노드를 모두 가진 경우

    else{//: 왼쪽 자식중 가장 큰 값 or 오른쪽자식중 가장 작은 값으로 대체. dNode가 부모노드와 자식노드가쭈루룩있기 때문에 연결은 건들지 않고 값만 바꾼다. 
        //전자로 구현      
    
        Node *bigofleft = Getleftsubtree(dNode);
        Node *pofbig = dNode;
        int d_data;
        while(Getrightsubtree(bigofleft)!=NULL){
            pofbig = bigofleft;
            bigofleft=Getrightsubtree(bigofleft); //왼쪽 자식 중 가장 큰 값 찾기 
        } 
       //d_data = GetData(dNode);//backup data
       // SetData(dNode,GetData(bigofleft)); 

        if(Getleftsubtree(pofbig)==bigofleft){ //while문 돌 필요 없이 바로 발견. (else문 첫 두줄),즉 dNode의 왼쪽자식에게 오른쪽자식이 없는 상황
            ChangeLeftsubtree(pofbig,Getleftsubtree(bigofleft));//pofbig(dNode)의 왼쪽줄에 bigofleft의 왼쪽자식 연결.
        }
        else ChangeRightsubtree(pofbig,Getleftsubtree(bigofleft));//삭제할 노드의 왼쪽섭트리 중 가장 큰 노드, 즉 dNode의 왼쪽자식의 오른쪽 자식 중 젤 밑에 있는 애가 bigofleft.
                                                                //그러면 bigofleft는 왼쪽자식 뿐이니까(아예 자식 없거나)pofbig의 오른줄을 bigofleft의 왼쪽자식에게 연결.
        dNode = bigofleft;

    }
    if(Getrightsubtree(dummyroot)!=*root) *root = Getrightsubtree(dummyroot); //삭제된 노드가 root노드일때 root노드를 업데이트
    delete dummyroot;

    return deldata;
}

int main(){
    Node *root1;

    BSTinit(&root1);//**root
    BSTinsert(&root1,3);
    BSTinsert(&root1,2);
    BSTinsert(&root1,4);
    BSTinsert(&root1,1);
    BSTinsert(&root1,5);

    cout<<"Show Tree1:";
    PreorderTraverse(root1);
   
    Search(root1,3);

     cout<<"Deleted Node:"<<BSTremove(&root1,4)<<endl;
    cout<<"Deleted Node:"<<BSTremove(&root1,1);

    cout<<endl<<"Show Tree1:";
    PreorderTraverse(root1);

    return 0;
}

