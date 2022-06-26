#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;
int CountSubsets(vector<int>arr, int n, int i, int x){
    //Base case
    if(i==n){
        if(x==0){
            return 1;
        }
        else{
            return 0;
        }
    }

    //Recursive case
    int inc = CountSubsets(arr, n, i+1, x-arr[i]);
    int exc = CountSubsets(arr,n,i+1,x);
    return inc+exc;
}
int main(){
    int n;
    cin>>n;
    vector<int>arr;
    for(int i=0;i<n;i++){
        int t;
        cin>>t;
        arr.push_back(t);
    }
    int x;
    cin>>x;
    cout<<CountSubsets(arr,n,0,x)<<endl;
    return 0;
}