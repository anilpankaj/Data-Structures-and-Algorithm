#include<bits/stdc++.h>
using namespace std;
void AllIndicesNum(int arr[], int n, int k){
    vector<int>q;
    if(n==0){
        if(arr[n]==k){
            q.push_back(n);
            return;
        }
        else{
            return;
        }
    }
    if(arr[n]==k){
        q.push_back(n);
    }
    AllIndicesNum(arr,n-1,k);
    for(int i=0;i<q.size();i++){
        cout<<q[i]<<" ";
    }
    //cout<<endl;
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
    AllIndicesNum(arr,n-1,k);
    return 0;
}