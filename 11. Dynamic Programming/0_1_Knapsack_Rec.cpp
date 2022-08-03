#include<bits/stdc++.h>
using namespace std;
int Knapsack_Rec(int val[], int wt[], int n, int w){
    if(n==0 || w==0){
        return 0;
    }

    // choice to take or leave value
    if(wt[n-1]<=w){
        return max(val[n-1] + Knapsack_Rec(val,wt,n-1,w-wt[n-1]), 0 + Knapsack_Rec(val,wt,n-1,w));
    }
    else if(wt[n-1]>w){
        return 0 + Knapsack_Rec(val,wt,n-1,w);
    }
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
    cout<<Knapsack_Rec(val,wt,n,w)<<endl;
    return 0;
}