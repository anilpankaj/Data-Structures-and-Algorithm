#include<bits/stdc++.h>
using namespace std;
int trappedWater(vector<int>arr){
    int n = arr.size();
    vector<int>la(n,0); //left array
    vector<int>ra(n,0); //right array
    
    //base case
    if(n<=2){
        return 0;
    }
    //let's fill left la and right ra array with higest level
    la[0] = arr[0];
    ra[n-1] = arr[n-1];
    for(int i=1;i<n;i++){
        la[i] = max(la[i-1],arr[i]);
        ra[n-i-1] = max(ra[n-i],arr[n-i-1]);
    }

    //let's check & print the la
    cout<<"print the value of left array"<<endl;
    for(int i=0;i<la.size();i++){
        cout<<la[i]<<" ";
    }
    cout<<endl;
    
    //let's check & print ra
    cout<<"print the value of right array"<<endl;
    for(int i=0;i<ra.size();i++){
        cout<<ra[i]<<" ";
    }
    cout<<endl;

    //let's calculate the trapped water
    int water = 0;
    for(int i=0;i<n;i++){
        water = water + min(la[i],ra[i]) - arr[i];
    }
    cout<<"print the value of trapped water"<<endl;
    return water;
}
int main(){
    int n;
    cout<<"enter the size of the array"<<endl;
    cin>>n;
    vector<int>arr;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        arr.push_back(x);
    }
    cout<<trappedWater(arr)<<endl;
    return 0;
}