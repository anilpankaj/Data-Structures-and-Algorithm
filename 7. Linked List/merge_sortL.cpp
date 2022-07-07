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
void InsertAThead(Node *&head, int data){
    if(head==NULL){
        head = new Node(data);
        return;
    }
    //otherwise
    Node *n = new Node(data);
    n->next = head;
    head = n; 
}
Node* midpoint(Node * head){
    Node *slow = head;
    Node *fast = head->next;

    while(fast!=NULL and fast->next!=NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
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
Node* Merge_sort(Node * head){
    //base case
    if(head==NULL or head->next==NULL){
        return head;
    }
    //otherwise
    //rec
    Node *mid = midpoint(head);
    
    //break at the mid
    Node *a = head;
    Node *b = mid->next;
    mid->next = NULL;

    //rec sort
    a = Merge_sort(a);
    b = Merge_sort(b);

    //merge
    return Merge_list(a,b);
}
void Print_list(Node * head){
    while(head!=NULL){
        cout<<head->data<<"->";
        head = head->next;
    }
    cout<<endl;
}
int main(){
    Node *head = NULL;
    InsertAThead(head,8);
    InsertAThead(head,2);
    InsertAThead(head,6);
    InsertAThead(head,1);
    InsertAThead(head,7);
    InsertAThead(head,9);
    InsertAThead(head,3);
    InsertAThead(head,5);
    InsertAThead(head,4);
    Print_list(head);
    head = Merge_sort(head);
    Print_list(head);
    return 0;
}