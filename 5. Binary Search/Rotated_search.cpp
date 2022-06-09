#include<bits/stdc++.h>
#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
int rotated_search(vector<int>arr, int key){
    int s = 0;
    int e = arr.size()-1;

    while(s<=e){
        int mid = (s+e)/2;
        if(arr[mid]==key){
            return mid;
        }
        // now we are checking the mid point in which line it's lie on
        //two cases
        if(arr[s]<=arr[mid]){
            //left 
            if(key>=arr[s] and key<=arr[mid]){
                e = mid - 1;
            }
            else{
                s = mid + 1;
            }
        }
        else{
            //right
            if(key>=arr[mid] and key<=arr[e]){
                s = mid + 1;
            }
            else{
                e = mid - 1;
            }
        }
    }
    return -1;
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
     int ele;
     cin>>ele;
     cout<<rotated_search(arr,ele)<<endl;
    return 0;
}