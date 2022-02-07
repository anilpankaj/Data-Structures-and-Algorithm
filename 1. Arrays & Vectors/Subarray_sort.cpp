#include<bits/stdc++.h>
using namespace std;

bool outofpair(vector<int>arr, int i){
    int x = arr[i];
    //corner cases
    if(i==0){
        return x>arr[1];
    }
    if(i==arr.size()-1){
        return x<arr[arr.size()-i-1];
    }
    return x>arr[i+1] or x<arr[i-1];
}
pair<int, int> subarray_sort(vector<int>arr){
    int n = arr.size();
    int largest = INT_MIN;
    int smallest = INT_MAX;

    for(int i=0;i<n;i++){
        int x = arr[i];
        if(outofpair(arr,i)){
            smallest = min(smallest,x);
            largest = max(largest,x);
        }
    }
    if(smallest == INT_MAX){
        return {-1,-1};
    }

    int left = 0;
    while (arr[left]<=smallest)
    {
        /* code */
        left++;
    }
    int right = n-1;
    while (arr[right]>=largest)
    {
        /* code */
        right--;
    }
    return {left,right};  
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
    //method-1(not efficeint) brute(NLogN Time + O(LogN) Space.
    /*
    if(n<2){
        return {-1,1};
    }
    vector<int>brr(arr);
    sort(arr.begin(),arr.end());

    int st = INT_MAX, en = INT_MIN;
    int count=0;
    for(int i=0;i<n;i++){
        if(arr[i]!=brr[i]){
            count++;
            st = min(st,i);
            en = max(en, i);
        }
    }
    if(count==0){
        return {-1,1};
    }
    else{
        cout<<st<<" "<<en<<endl;
    }
    */

    //method 2
    auto p = subarray_sort(arr);
    cout<<p.first<<" and "<<p.second<<endl;
    return 0;
}