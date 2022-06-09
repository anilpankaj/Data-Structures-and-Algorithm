#include<bits/stdc++.h>
using namespace std;
int binary_upper_bound(vector<int>arr, int key){
    int s = 0;
    int e = arr.size()-1;
    int ans = -1;
    while (s<=e)
    {
        int mid = (s+e)/2;
        if(arr[mid]==key){
            ans = mid;
            s = mid + 1;
        }
        else if(arr[mid]>key){
            e = mid - 1;
        }
        else{
            s = mid + 1;
        }
    }
    return ans;
}
int binary_lower_bound(vector<int>arr, int key){
    int s = 0;
    int e = arr.size()-1;
    int ans = -1;
    while(s<=e){
        int mid = (s+e)/2;
        if(arr[mid]==key){
            ans = mid;
            e = mid - 1;
        }
        else if(arr[mid]>key){
            e = mid - 1;
        }
        else{
            s = mid + 1;
        }
    }
    return ans;
}
int main(){
    int n;
    cin>>n;
    vector<int>arr;
    
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        arr.push_back(x);
    }
    int k;
    cin>>k;
    cout<<binary_upper_bound(arr, k) - binary_lower_bound(arr, k) + 1<<endl;
    return 0;
}