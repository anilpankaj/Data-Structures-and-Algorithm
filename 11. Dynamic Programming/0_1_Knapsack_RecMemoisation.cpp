#include<bits/stdc++.h>
using namespace std;

class Knapsack{
    public:
        int fxn(int val[],int wt[],int n,int w, vector<vector<int>>&t){
            if(n==0 || w==0){
                return 0;
            }
            if(wt[n-1]<=w){
                t[n][w] =  max(val[n-1] + fxn(val,wt,n-1,w-wt[n-1],t), 0 + fxn(val,wt,n-1,w,t));
                return t[n][w];
            }
            else if(wt[n-1]>w){
                t[n][w] = 0 + fxn(val,wt,n-1,w-wt[n-1],t);
                return t[n][w];
            }
        }
        int Knapsack_RecMemoisation(int val[],int wt[],int n,int w){
            vector<vector<int>>t(n+1,vector<int>(w+1,-1));
            return fxn(val,wt,n,w,t);
        }

};
int main(){
    Knapsack ob;
    int n,w;
    cin>>n>>w;
    int val[n],wt[n];
    for(int i=0;i<n;i++){
        cin>>val[i];
    }
    for(int i=0;i<n;i++){
        cin>>wt[i];
    }
    cout<<ob.Knapsack_RecMemoisation(val,wt,n,w)<<endl;
    return 0;
}