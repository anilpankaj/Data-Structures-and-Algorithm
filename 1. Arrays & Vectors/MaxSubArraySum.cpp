#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int curnt = 0;
    int max_sum = INT_MIN;
    
    for(int i=0;i<n;i++){
        curnt = curnt + arr[i];
        if(max_sum<curnt){
            max_sum = curnt;
        }
        if(curnt<0){
            curnt = 0;
        }
        
        
        /*if(curnt<0){
            curnt = 0;
        }
        else{
            max_sum = max(max_sum, curnt);
        }*/
    }
    cout<<"max subArray sum: "<<max_sum<<endl;
    return 0;
}