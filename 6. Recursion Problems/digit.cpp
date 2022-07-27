#include<bits/stdc++.h>
using namespace std;
int Tdigits(int n){
    if(n>=0 and n<10){
        return 1;
    }
    int temp = Tdigits(n/10);
    return 1+temp;
}
int main(){
    int n;
    cin>>n;
    cout<<Tdigits(n)<<endl;
    return 0;
}