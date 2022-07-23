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
Node* BuildTree(){
    int d;
    cin>>d;
    
    if(d==-1){
        return NULL;
    }
    Node *n = new Node(d);
    n->left = BuildTree();
    n->right = BuildTree();

    return n;
}

int HeightTree(Node*root){
    if(root==NULL){
        return 0;
    }
    int h1 = HeightTree(root->left);
    int h2 = HeightTree(root->right);
    return 1 + max(h1,h2);
}
int SimplifyDiameter(Node*root){
    //base case
    if(root==NULL){
        return 0;
    }
    //rec case
    int d1 = HeightTree(root->left) + HeightTree(root->right);  //time o(n)
    int d2 = SimplifyDiameter(root->left);  // both
    int d3 = SimplifyDiameter(root->right); // time o(n) === total time comp = O(n^2) will optimise in next code

    return max(d1,max(d2,d3));
}
int main(){
    Node*root = BuildTree();
    HeightTree(root);
    cout<<SimplifyDiameter(root)<<endl;
    return 0;
}