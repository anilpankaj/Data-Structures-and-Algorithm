#include<bits/stdc++.h>
using namespace std;
int Knapsack_tabulation(int val[],int wt[],int n, int w){
    int t[n+1][w+1];
    for(int i=0;i<n+1;i++){
        for(int j=0;j<w+1;j++){
            if(i==0 || j==0){
                t[i][j] = 0;
            }
        }
    }

    for(int i=1;i<n+1;i++){
        for(int j=1;j<w+1;j++){

            //if we have choice
            if(wt[i-1]<=j){
                t[i][j] = max(val[i-1] + t[i-1][j-wt[i-1]], 0 + t[i-1][j]);
            }
            //if we don't have any choice
            else if(wt[i-1]>j){
                t[i][j] = 0 + t[i-1][j];
            }        
        }
    }
    return t[n][w];
}
int main(){
    int n,w;
    cin>>n>>w;
    int val[n],wt[n];
    for(int i=0;i<n;i++){
        cin>>val[i];
    }
    for(int i=0;i<n;i++){
        cin>>wt[i];
    }
    cout<<Knapsack_tabulation(val,wt,n,w)<<endl;
    return 0;
}