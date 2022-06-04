#include<bits/stdc++.h>
using namespace std;

int partition(vector<int>&a, int s, int e){
    int pivot = a[e];
    int i = s-1;
    for(int j=s;j<e;j++){
        if(a[j]<pivot){
            i++;
            swap(a[i],a[j]);
        }
    }
    swap(a[i+1],a[e]);
    return i+1;
}
int quickselect(vector<int>arr,int s, int e, int k){
    int p = partition(arr,s,e);
    if(p==k){
        return arr[p];
    }
    else if(k<p){
        return quickselect(arr,s,p-1,k);
    }
    else{
        return quickselect(arr,p+1,e,k);
    }
}
int main(){
    
    vector<int>arr{10,5,2,0,7,6,4};
    int n = arr.size();
    int k;
    cin>>k;
    cout<<quickselect(arr,0,n-1,k)<<endl;
    return 0;
}