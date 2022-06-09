#include<bits/stdc++.h>
#include<vector>
#include<iostream>
using namespace std;

int Partition(vector<int>&arr, int s,int e){
    int i = s-1;
    int pivot = arr[e];
    for(int j=s;j<e;j++){
        if(arr[j]<pivot){
            i++;
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[i+1],arr[e]);
    return i+1;
}

int QuickSort(vector<int>&arr, int s, int e){
    //base case
    if(s>=e){
        return 0;
    }
    //recursive case
    int p = Partition(arr,s,e);
    QuickSort(arr,s,p-1);
    QuickSort(arr,p+1,e);

}
int main(){
    int n;
    cin>>n;
    vector<int>arr;
    for(int i=0;i<n;i++){
        int ele;
        cin>>ele;
        arr.push_back(ele);
    }
    QuickSort(arr,0,n-1);

    for(int x:arr){
        cout<<x<<" ";
    }
    cout<<endl;
    return 0;
}