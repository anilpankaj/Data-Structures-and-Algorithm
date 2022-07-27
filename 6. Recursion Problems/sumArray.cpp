#include<bits/stdc++.h>
using namespace std;
int findSum(int arr[], int n){
    if(n==0){
        return arr[0];
    }
    
    int sum = arr[n] + findSum(arr,n-1);
    return sum;
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<findSum(arr,n-1)<<endl;
    return 0;
}