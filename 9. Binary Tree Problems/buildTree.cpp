#include<bits/stdc++.h>
#include<iostream>
#include<queue>
using namespace std;

class Node{
    public:
        int data;
        Node *left, *right;

        //public constructor
        Node(int d){
            data = d;
            left = NULL;
            right = NULL;
        }
};
Node * BuildTree(){
    int d;
    cin>>d;

    if(d==-1){
        return NULL;
    }

    Node* n = new Node(d);
    n->left = BuildTree();
    n->right = BuildTree();

    return n;
}
void LevelOrderPrint(Node*root){
    queue<Node*>q;
    q.push(root);
    q.push(NULL);
    while (!q.empty())
    {
        Node* temp = q.front();
        if(temp==NULL){
            cout<<endl;
            q.pop();
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            q.pop();
            cout<<temp->data<<" ";
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }
    }
    return;
}
int main(){
    Node *root = BuildTree();
    //levelorderPrint
    LevelOrderPrint(root);

    return 0;
}