#include<bits/stdc++.h>
using namespace std;
bool check(int k, int arr[], int n, int dis){
    int count = 1;
    int last_post = arr[0];
    for(int i=1;i<n;i++){
        if(arr[i]-last_post>=dis){
            last_post = arr[i];
            count++;
        }
        if(count==k){
            return true;
        }
    }
    return false;
}
int find_max_distance(int arr[], int n, int k){
    int s = 0;
    int e = arr[n-1]-arr[0]; 
    
    int res = -1;
    while(s<=e){
        int mid = (s+e)/2; // mid = start + (end-start)/2  used for long long int
        if(check(k,arr,n,mid)){
            res = mid;
            s = mid+1;
        }
        else{
            e = mid-1;
        } 
    }
    return res;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        int arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        sort(arr,arr+n);
        cout<<find_max_distance(arr,n,k)<<endl;
    }
    return 0;
}