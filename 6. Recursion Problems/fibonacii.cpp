#include<bits/stdc++.h>
using namespace std;
int Fib(int n){
    if(n==0){
        return 0;
    }
    if(n==1){
        return 1;
    }
    int num = Fib(n-1) + Fib(n-2);
    return num;
}
int main(){
    int n;
    cin>>n;
    cout<<Fib(n)<<" ";
    return 0;
}