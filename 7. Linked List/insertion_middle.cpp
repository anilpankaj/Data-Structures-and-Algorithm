#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
        int data;
        Node * next;
        //class constructor
        Node(int data){
            this->data = data;
            next = NULL;
        }
};
void insertion(Node* &head, int data){
    if(head==NULL){
        head = new Node(data);
        return;
    }
    Node * nd = new Node(data);
    nd->next = head;
    head = nd;
}
void Insert_middle(Node* &head, int pos, int data){
    if(pos==0){
        insertion(head,data);
    }
    else{
        Node * temp = head;
        for(int i=1;i<pos;i++){
            temp = temp->next;
        }
        Node * n = new Node(data);
        n->next = temp->next;
        temp->next = n; 
    }
}
void print_list(Node *head){
    while(head!=NULL){
        cout<<head->data<<"-->";
        head = head->next;
    }
    cout<<endl;
}
int main(){
    Node * head = NULL;
    int pos;
    cin>>pos;
    insertion(head,5);
    insertion(head,4);
    insertion(head,2);
    insertion(head,1);
    insertion(head,0);
    Insert_middle(head,pos,3);
    print_list(head);
    return 0;
}