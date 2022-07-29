#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    //method1
    /*
    int res = 1;
    int min_sum = 1, max_sum = 1;
    for(int i=0;i<n;i++){
        //check all elements one by one
        if(arr[i]>0){
            max_sum = max_sum*arr[i];
            min_sum = min(1,min_sum*arr[i]);
        }
        else if(arr[i]<0){
            int temp = max_sum;
            max_sum = max(1,min_sum*arr[i]);
            min_sum = temp*arr[i];
        }
        else{
            min_sum = 1;
            max_sum = 1;
        }
        res = max(res,max_sum);
    }
    cout<<res<<endl;
    */

   //method 2
   int i=0;
   int j=n-1;
   long long int res = INT_MIN;
   long long int min_sum = 1, max_sum = 1;
   while(i<n and j>=0){
    max_sum *= arr[i];
    min_sum *= arr[i];
    res = max(res,max(max_sum,min_sum));
    if(arr[i]==0){
        max_sum = 1;
    }
    if(arr[j]==0){
        min_sum = 1;
    }
    i++;
    j++;
   }
    cout<<res<<endl;
    return 0;
}