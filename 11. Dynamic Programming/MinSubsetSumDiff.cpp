#include<bits/stdc++.h>
using namespace std;
int MinSumPartition(int arr[], int n, int w){
    int t[n+1][w+1];
    for(int i=0;i<n+1;i++){
        for(int j=0;j<w+1;j++){
            if(i==0)
                t[i][j] = 0;
            if(j==0)
                t[i][j] = 1;
        }
    }

    for(int i=1;i<n+1;i++){
        for(int j=1;j<w+1;j++){
            //if we have choice
            if(arr[i-1]<=j){
                t[i][j] = t[i-1][j-arr[i-1]] || t[i-1][j];
            }
            else if(arr[i-1]>j){
                t[i][j] = t[i-1][j];
            }
        }
    }
    int x = w/2; //array ko half kar diya taki because s1 smaller hoga 
    while(t[n][x]==0){ //last row me jab tak traves krnege jab tak hmko true nahi mil jatha
        x--;
    }
    return w-2*x;  // sum - 2*s1
}
int minDiffrence(int arr[], int n){
    int sum =0;
    for(int i=0;i<n;i++){
        sum += arr[i];
    }
    return MinSumPartition(arr,n,sum);
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<minDiffrence(arr,n)<<endl;
    return 0;
}