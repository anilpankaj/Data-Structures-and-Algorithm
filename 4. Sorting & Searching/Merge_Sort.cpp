#include<vector>
#include<bits/stdc++.h>
using namespace std;

void merge(vector<int>&array,int s, int e){
    int i = s;
    int mid = (s+e)/2;
    int j = mid+1;
    vector<int>temp;
    while(i<=mid and j<=e){
        if(array[i]<array[j]){
            temp.push_back(array[i]);
            i++;
        }
        else{
            temp.push_back(array[j]);
            j++;
        }
    }

    while(i<=mid){
        temp.push_back(array[i++]);
    }
    while(j<=e){
        temp.push_back(array[j++]);
    }
    int k=0;
    for(int idx=s; idx<=e; idx++){
        array[idx] = temp[k++];
    }
    return;
}
void mergesort(vector<int>&array, int s, int e){
    //base case
    if(s>=e){
        return;
    }
    int m = (s+e)/2;
    mergesort(array,s,m);
    mergesort(array, m+1,e);
    return merge(array,s,e);
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
    int s = 0;
    int e = arr.size()-1;
    mergesort(arr,s,e);
    for(int ele: arr){
        cout<<ele<<" ";
    }
    cout<<endl;
    return 0;
}