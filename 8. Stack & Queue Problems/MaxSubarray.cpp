#include<iostream>
#include<vector>
#include<deque>
using namespace std;
// 1) brute force method
/*
void MaxSubarrayEle(vector<int>arr, int n, int k){
    int largest = INT_MIN;
    for(int i=0;i<n-k+1;i++){
        for(int j=i+1;j<k+i;j++){
            if(arr[i]<arr[j]){
                largest = max(largest,arr[j]);
            }
            else{
                largest = max(largest,arr[i]);
            }
        }
        cout<<largest<<" ";
    }
}*/

// 2) sliding window method
void MaxSubarrayEle(vector<int>arr, int n, int k){
    deque<int>dq(k);
    //algorithm 
    //process only the first k elements
    int i;
    for(i=0;i<k;i++){
        while(!dq.empty() and arr[i]>arr[dq.back()]){
            dq.pop_back();
        }
        dq.push_back(i);
    }
    //Remaining the elements of the array
    for( ;i<=n;i++){
        cout<<arr[dq.front()]<<" ";
        while (!dq.empty() && dq.front() <= i-k) //to check if our window element is out of bond or not if it's out of bound then we pop it.
        {
            dq.pop_front();
        }
        while (!dq.empty() && arr[i]>=arr[dq.back()]) 
        {
            dq.pop_back();
        }
        //always
        dq.push_back(i);
    }
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
    MaxSubarrayEle(arr,n,k);
    return 0;
}