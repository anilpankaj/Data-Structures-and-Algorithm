#include<bits/stdc++.h>
using namespace std;
int highest_mountain(vector<int>arr){
    int n = arr.size();
    int largest = 0;
    for(int i=1;i<=n-1;){
        //check arr[i] is peak or not
        if(arr[i]>arr[i-1] && arr[i]>arr[i+1]){
            //do some work
            int count = 1;
            int j = i;
            //count backward(left)
            while(j>=1 and arr[j]>arr[j-1]){
                j--;
                count++;
            }
            //count forward(right)
            while(i<=n-2 and arr[i]>arr[i+1]){
                i++;
                count++;
            }
            largest = max(largest,count);
        }
        else{
            i++;
        }
    }
    return largest;
}
int main(){
    int n;
    cout<<"enter the size of the array"<<endl;
    cin>>n;
    vector<int>arr;
    cout<<"enter the elements of the array"<<endl;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        arr.push_back(x);
    }
    cout<<"Highest Mountain: "<<highest_mountain(arr)<<endl;
    return 0;
}