#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
        int data;
        Node * next;
        //public constructor
        Node(int data){
            this->data = data;
            next = NULL;
        }
};
void Insertion(Node * &head, int data){
    if(head==NULL){
        head = new Node(data);
        return;
    }
    Node * n = new Node(data);
    n->next = head;
    head = n;
}
Node* Reverse_list(Node * head){ //using recursion
     //Base case
     if(head == NULL or head->next == NULL){
        return head;
     }
     //otherwise
     Node* shead = Reverse_list(head->next);
     head->next->next = head;
     head->next = NULL;
     return shead;
}
void Print_list(Node * head){
    while(head!=NULL){
        cout<<head->data<<"-->";
        head = head->next;
    }
    cout<<endl;
}
int main(){
    Node * head = NULL;
    Insertion(head,5);
    Insertion(head,4);
    Insertion(head,3);
    Insertion(head,2);
    Insertion(head,1);
    Print_list(head);
    cout<<endl;
    head = Reverse_list(head);
    Print_list(head);
    return 0;
}