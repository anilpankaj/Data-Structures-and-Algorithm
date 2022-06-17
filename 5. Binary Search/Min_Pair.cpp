#include<bits/stdc++.h>
using namespace std;
int min_pair(vector<int>arr1,vector<int>arr2, int n, int m){
    //sort the array
    sort(arr2.begin(),arr2.end());

    int p1,p2;
    int diff = INT_MAX;

    //iteratte over first array and look for closes elements in the second array
    for(int x: arr1){
        auto lb = lower_bound(arr2.begin(),arr2.end(),x)-arr2.begin();

        //left
        if(lb>=1 and x-arr2[lb-1]<diff){
            diff = x-arr2[lb-1];
            p1 = x;
            p2 = arr2[lb-1];
        }
        //greater /right
        if(lb!=arr2.size() and arr2[lb]-x<diff){
            diff = arr2[lb]-x;
            p1 = x;
            p2 = arr2[lb];
        }
    }   
    cout<<"min_par: "<<p1<<" and "<<p2<<endl;
    return 0;
}
int main(){
    int n,m;
    cin>>n>>m;
    vector<int>arr1;
    vector<int>arr2;
    for(int i=0;i<n;i++){
        int x1;
        cin>>x1;
        arr1.push_back(x1);
    }
    for(int i=0;i<m;i++){
        int x2;
        cin>>x2;
        arr2.push_back(x2);
    }
    min_pair(arr1,arr2,n,m);
    return 0;
}