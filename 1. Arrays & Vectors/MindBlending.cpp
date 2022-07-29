#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int arr[n];
    long int pro[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    long temp1 = 1;
    long temp2 = 1;

    //calculate left product array
    pro[0] = temp1;
    for(int i=1;i<n;i++){
        temp1 *= arr[i-1];
        pro[i] = temp1;
    }

    //calculate from right product of array

    for(int i=n-2;i>=0;i--){
        temp2 *= arr[i+1];
        pro[i] *= temp2;
    }
    for(int i=0;i<n;i++){
        cout<<pro[i]<<" ";
    }
    cout<<endl;
    return 0;
}