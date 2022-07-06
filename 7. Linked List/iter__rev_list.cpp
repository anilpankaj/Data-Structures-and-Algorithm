#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
        int data;
        Node*next;
    //public constroctor
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
    Node *n = new Node(data);
    n->next = head;
    head = n;

}
void Iter_rev_list(Node *&head){
    Node * curr_node = head;
    Node * prev_node = NULL;
    Node * next_node;
    while(curr_node!=NULL){
        next_node = curr_node->next;
        curr_node->next = prev_node;
        prev_node = curr_node;
        curr_node = next_node;
    }
    head = prev_node;
    return;
}
void Print_list(Node *head){
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
    Insertion(head,0);
    Print_list(head);
    Iter_rev_list(head);
    cout<<endl;
    Print_list(head);
    return 0;
}