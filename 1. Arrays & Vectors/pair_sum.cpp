#include<bits/stdc++.h>
using namespace std;
vector<int>pair_sum(vector<int>arr, int sum){
    unordered_set<int>s;
    vector<int>result;
    for(int i=0;i<arr.size();i++){
        int x = sum - arr[i];
        if(s.find(x)!=s.end()){
            result.push_back(x);
            result.push_back(arr[i]);
            return result;
        }
        s.insert(arr[i]);
    }
    return {};
}
int main(){
    vector<int>arr;
    int n;
    cout<<"enter the size of the array "<<endl;
    cin>>n;

    cout<<"enter the array elements"<<endl;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        arr.push_back(x);
    }

    int s;
    cout<<"enter the target element"<<endl;
    cin>>s;

    auto p = pair_sum(arr,s);
    if(p.size()==0){
        cout<<"No such pair"<<endl;
    }
    else{
        cout<<"pair: "<<p[0]<<","<<p[1]<<endl;
    }
    return 0;
}