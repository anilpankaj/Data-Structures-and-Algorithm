#include<bits/stdc++.h>
using namespace std;
class Node{
public:
    int data;
    Node*next;
    //public constructor
    Node(int data){
        this->data = data; // if you using same name then use this pointer
        next = NULL;
    }

};
//----------------Linked List-----------------
void InsertNode(Node* &head, int data){
    //Base case
    if(head==NULL){
        head = new Node(data);
        return;
    }
    //otherwise
    Node * n = new Node(data);
    n->next = head;
    head = n;
}
void PrintNode(Node * head){
    while(head!=NULL){
        cout<<head->data;
        cout<<"-->";
        head = head->next;
    }
    cout<<endl;
}
int main(){
    Node*head = NULL;
    InsertNode(head,5);
    InsertNode(head,4);
    InsertNode(head,3);
    InsertNode(head,2);
    InsertNode(head,1);
    InsertNode(head,0);
    PrintNode(head);
    return 0;
}