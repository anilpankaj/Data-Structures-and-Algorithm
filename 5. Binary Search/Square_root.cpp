#include<bits/stdc++.h>
using namespace std;
float sqr_root(int n, int p){
    int s = 0;
    int e = n;
    float res = 0;
    // Binary search (search 0...9)(for integer)
    while(s<=e){
        int mid = (s+e)/2;
        if(mid*mid==n){
            return mid;
        }
        else if(mid*mid<n){
            res = mid;
            s = mid + 1;
        }
        else{
            e = mid - 1;
        }
    }
    //Linear Search for floating digits
    float inc = 0.1;
    for(int spc=1; spc<=p; spc++){
        //do linear search
        while(res*res<=n){
            res += inc;
        }
        //back one step
        res = res - inc;
        inc = inc/10.0;
    }
    return res;
}
int main(){
    int n,p;
    cin>>n>>p;
    cout<<sqr_root(n,p)<<endl;
    return 0;
}