#include<bits/stdc++.h>
using namespace std;
int Power(int x, int n){
    if(x==0){
        return 0;
    }
    if(n==0 or x==1){
        return 1;
    }
    if(n==1){
        return x;
    }
    int pwr = x*Power(x,n-1);
    return pwr;
}
int main(){
    int x;
    cin>>x;
    int n;
    cin>>n;
    cout<<Power(x,n)<<endl;
    return 0;
}