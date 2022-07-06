#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
        int data;
        Node * next;
    //public constroctor
    Node(int data){
        this->data = data;
        next = NULL;
    }
};
void Insertion(Node * &head, int data){
    if(head == NULL){
        head = new Node(data);
        return;
    }
    //otherwise
    Node * n = new Node(data);
    n->next = head;
    head = n;
}
Node* Rec_Rev_Kth(Node * head, int k){
    Node *curr = head;
    Node * prev = NULL;
    Node * nxt;
    int cnt = 1;
    while(curr!=NULL && cnt<=k){
        nxt = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nxt; 
        cnt++;
    }
    if(nxt!=NULL){
        head->next = Rec_Rev_Kth(nxt,k);
    }
    return prev;
}
void Print_list(Node * head){
    while(head!=NULL){
        cout<<head->data<<"->";
        head = head->next;
    }
    cout<<endl;
}
int main(){
    Node * head = NULL;
    int k;
    cin>>k;
    Insertion(head,9);
    Insertion(head,6);
    Insertion(head,5);
    Insertion(head,1);
    Insertion(head,2);
    Insertion(head,4);
    Insertion(head,3);
    Insertion(head,8);
    Insertion(head,7);
    Print_list(head);
    head = Rec_Rev_Kth(head,k);
    cout<<endl;
    Print_list(head);
    return 0;
}