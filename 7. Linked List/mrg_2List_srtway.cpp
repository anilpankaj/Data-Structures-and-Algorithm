#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
        int data;
        Node *next;
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
    //otherwise
    Node *n = new Node(data);
    n->next = head;
    head = n;
}
Node* Merge_list(Node *h1, Node * h2){
    //base case
    if(h1==NULL){
        return h2;
    }      
    if(h2==NULL){
        return h1;
    }      

    //rec case
    Node *c;
    if(h1->data < h2->data){
        c = h1;
        c->next = Merge_list(h1->next, h2);
    }                
    else{
        c = h2;
        c->next = Merge_list(h1, h2->next);
    }    
    return c;
}
void Print_list(Node * head){
    while(head!=NULL){
        cout<<head->data<<"->";
        head = head->next;
    }
    cout<<endl;
}
int main(){
    Node * head1 = NULL;
    Node * head2 = NULL;
    Insertion(head1,1);
    Insertion(head1,5);
    Insertion(head1,7);
    Insertion(head1,10);
    Insertion(head2,2);
    Insertion(head2,3);
    Insertion(head2,6);
    Print_list(head1);
    Print_list(head2);
    Node *head = Merge_list(head1,head2);
    Print_list(head);
    return 0;
}