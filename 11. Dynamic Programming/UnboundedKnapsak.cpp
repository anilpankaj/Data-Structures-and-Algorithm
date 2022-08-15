#include<bits/stdc++.h>
using namespace std;
int Unbounded_knap(int leng[], int price[],int n, int w){
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
            // if we have a choice
            if(price[i-1]<=j){
                t[i][j] = max(leng[i-1] + t[i][j-price[i-1]], t[i-1][j]);
            }
            else{
                t[i][j] = t[i-1][j];
            }
        }
    }
    return t[n][w];
}
int main(){
    int n;
    cin>>n;
    int w;
    cin>>w;
    int length[n], price[n];
    for(int i=0;i<n;i++){
        cin>>length[i];
    }
    for(int i=0;i<n;i++){
        cin>>price[i];
    }
    cout<<Unbounded_knap(length,price,n,w)<<endl;
    return 0;
}