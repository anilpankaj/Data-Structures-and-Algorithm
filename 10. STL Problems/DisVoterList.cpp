#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,k,m;
    cin>>n>>k>>m;
    int tt = n+k+m;
    int arr[tt];
    for(int i=0;i<tt;i++){
        cin>>arr[i];
    }
    sort(arr,arr+tt);
    vector<int>res;
    
    for(int i=0;i<tt;){
        int cnt=0;
        int j=i;
        while(j<tt && (arr[j]==arr[i])){
            cnt++;
            j++;
        }
        if(cnt>=2){
            res.push_back(arr[i]);
        }
        i = j;
    }
    cout<<res.size()<<endl; 
    for(int i=0;i<res.size();i++){
        cout<<res[i]<<" ";
    }   
    cout<<endl;
    return 0;
}