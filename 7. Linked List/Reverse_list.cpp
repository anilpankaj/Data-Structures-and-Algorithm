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
     
    

}
int main(){
    Node * head = NULL;
    Insertion(head,5);
    Insertion(head,4);
    Insertion(head,3);
    Insertion(head,2);
    Insertion(head,1);
    Reverse_list(head);
    return 0;
}