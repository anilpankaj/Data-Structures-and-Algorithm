#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll kadanes(int arr[], int n){
    ll crnt_sum = 0;
    ll max_sum = INT_MIN;
    for(int i=0;i<n;i++){
        crnt_sum = crnt_sum + arr[i];
        if(max_sum<crnt_sum){
            max_sum = crnt_sum;
        }
        if(crnt_sum<0){
            crnt_sum = 0;
        }
    }
    return max_sum;
}
ll K_concatination_sum(int arr[], int n, int k){

    ll kadanes_sum = kadanes(arr,n);
    // if k==1 then answer should be kadanes sum
    if(k==1){
        return kadanes_sum;
    }

    ll crnt_prefix=0, crnt_suffix=0;
    ll max_prefix_sum = INT_MIN, max_suffix_sum = INT_MIN;
    //calculate max prefix sum 
    for(int i=0;i<n;i++){
        crnt_prefix = crnt_prefix + arr[i];
        max_prefix_sum = max(max_prefix_sum,crnt_prefix);
    }

    //total sum
    ll total_sum = crnt_prefix;

    //calculate max suffix sum
    for(int i=n-1;i>=0;i--){
        crnt_suffix = crnt_suffix + arr[i];
        max_suffix_sum = max(max_suffix_sum,crnt_suffix);
    }
    ll res;
    if(total_sum<0){
        res = max(max_prefix_sum + max_suffix_sum, kadanes_sum);
    }
    else{
        res = max(max_prefix_sum + max_suffix_sum + (total_sum*(k-2)), kadanes_sum);
    } 
    return res;
}
int main(){
    int t;
    cin>>t;
    while (t--){
        int n,k;
        cin>>n>>k;
        int arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        cout<<K_concatination_sum(arr,n,k)<<endl;
    }
    return 0;
}