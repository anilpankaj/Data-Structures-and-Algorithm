#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
        int data;
        Node * next;
    //public constractor
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
    Node * n = new Node(data);
    n->next = head;
    head = n;
}
void Insert_pos(Node * &head, int count,int data){
    if(count==0){
        Insertion(head, data);
    }
    else{ //otherwise
        Node*temp1 = head;
        for(int i=1;i<=count;i++){
            temp1 = temp1->next;
        }
        Node*nd = new Node(data);
        nd->next = temp1->next;
        temp1->next = nd;
    }
    
}
void Find_ith_ele(Node * &head){
    //traverse list untill geting 1
    int count = 0;
    Node *temp = head;
    while(temp!=NULL){
        if(temp->data == 1){ 
            Insert_pos(head,count,50); 
        }
        //cout<<count<<endl;
        temp = temp->next;
        count++;
    }
}
void Print_list(Node * head){
    while(head!=NULL){
        cout<<head->data<<"-->";
        head = head->next;
    }
    cout<<endl;
}
int main(){
    Node*head = NULL;  
    //create List
    Insertion(head,5);
    Insertion(head,2);
    Insertion(head,1);
    Insertion(head,4);
    Insertion(head,5);
    Insertion(head,1);
    Find_ith_ele(head);
    Print_list(head);
    return 0;                                                                                                                                                               
}