#include<bits/stdc++.h>
using namespace std;

int solve(int arr[],int i, int j){
    // base condition
    if(i>=j){
        return 0;
    }
    int mn = INT_MAX;

    for(int k=i;k<=j-1;k++){
        int tempans = solve(arr,i,k) + solve(arr,k+1,j) + arr[i-1]*arr[k]*arr[j];
        if(tempans<mn){
            mn = tempans;
        }
    }
    return mn;
}
int MatrixChainMultiplication(int arr[], int n){
    return solve(arr,1,n-1);
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<MatrixChainMultiplication(arr,n)<<endl;
    return 0;   
}