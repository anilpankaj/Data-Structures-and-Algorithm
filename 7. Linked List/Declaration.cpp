#include<bits/stdc++.h>
using namespace std;
class Node{
    int data;
    Node*next;
    public:
        Node(int data){
            this->data = data;
            next = NULL;
        }
};
int main(){
    Node*n = new Node(10);
}