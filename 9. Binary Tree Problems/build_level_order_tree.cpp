#include<bits/stdc++.h>
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
Node* LevelOrderTree(){
    int t;
    cin>>t;
    Node* n = new Node(t);
    queue<Node*>q;
    q.push(n);
    while(!q.empty()){
        Node * current_node = q.front();
        q.pop();
        int d1,d2;
        cin>>d1>>d2;
        if(d1!=-1){
            current_node->left = new Node(d1);
            q.push(current_node->left);
        }
        if(d2!=-1){
            current_node->right = new Node(d2);
            q.push(current_node->right);
        }
    }
    return n;
}
void PrintLevelOrder(Node*root){
    queue<Node*>q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        Node*temp = q.front();
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
    Node*root = LevelOrderTree();
    PrintLevelOrder(root);
    return 0;
}