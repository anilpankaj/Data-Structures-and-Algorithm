#include<bits/stdc++.h>
using namespace std;
bool find_subsetSum(int arr[], int n, int w){
    bool t[n+1][w+1];

    for(int i=0;i<n+1;i++){
        for(int j=0;j<w+1;j++){
            if(i==0){
                t[i][j] = false;
            }
            if(j==0){
                t[i][j] = true;
            }
        }
    }

    for(int i=1;i<n+1;i++){
        for(int j=1;j<w+1;j++){

            //if we have choices to take element or not
            if(arr[i-1]<=j){
                t[i][j] = t[i-1][j-arr[i-1]] || t[i-1][j];
            }
            else if(arr[i-1]>j){
                t[i][j] = t[i-1][j];
            }  
        }
    }
    return t[n][w];
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int sum;
    cin>>sum;

    cout<<find_subsetSum(arr,n,sum)<<endl;
    return 0;
}