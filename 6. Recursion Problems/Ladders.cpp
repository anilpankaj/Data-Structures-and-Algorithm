#include<bits/stdc++.h>
using namespace std;
int CountWays(int n){
    //base case
    if(n<0){ // to avoid invalid state
        return 0;
    }

    if(n==0){
        return 1;
    }

    //Recursive case
    return CountWays(n-1) + CountWays(n-2) + CountWays(n-3);
}
int main(){
    int num;
    cin>>num;
    cout<<CountWays(num)<<endl;
    return 0;
}