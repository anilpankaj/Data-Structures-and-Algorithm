#include<bits/stdc++.h>
using namespace std;
bool findNum(int arr[], int n, int k){
    if(n==0){
        if(arr[n]==k){
            return true;
        }
        else{
            return false;
        }
    }
    if(arr[n]==k){
        return true;
    }
    findNum(arr,n-1,k);
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int k;
    cin>>k;
    bool temp = findNum(arr,n-1,k);
    if(temp){
        cout<<"true"<<endl;
    }
    else{
        cout<<"false"<<endl;
    }
    return 0;
}