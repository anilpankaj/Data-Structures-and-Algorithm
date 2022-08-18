#include<bits/stdc++.h>
using namespace std;

int solve(int arr[],int i, int j, vector<vector<int>>&t){
    // base condition
    if(i>=j){
        return 0;
    }

    if(t[i][j]!=-1){
        return t[i][j];
    }

    int mn = INT_MAX;

    for(int k=i;k<=j-1;k++){
        int tempans = solve(arr,i,k,t) + solve(arr,k+1,j,t) + arr[i-1]*arr[k]*arr[j];
        if(tempans<mn){
            mn = tempans;
        }
    }
    t[i][j] = mn;
    return t[i][j];
}
int MatrixChainMultiplication(int arr[], int n){
    vector<vector<int>>t(n+1,vector<int>(n+1,-1)); // intialize 2d matrix with -1;
    return solve(arr,1,n-1,t);
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