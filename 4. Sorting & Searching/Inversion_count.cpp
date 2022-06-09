#include<vector>
#include<bits/stdc++.h>
using namespace std;
int merge(vector<int>&array, int s, int e){
    int i = s;
    int m = (s+e)/2;
    int j = m+1;

    vector<int>temp;

    int cnt = 0;
    while(i<=m and j<=e){
        if(array[i]<array[j]){
            temp.push_back(array[i]);
            i++;
        }
        else{
            cnt += (m-i+1);
            temp.push_back(array[j]);
            j++;
        }
    }

    while (i<=m)
    {
        temp.push_back(array[i++]);
    }
    while (j<=e)
    {
        temp.push_back(array[j++]);
    }
    
    int k=0;

    for(int idx = s; idx<=e; idx++){
        array[idx] = temp[k++];
    }
    return cnt;

}

int inversion_count(vector<int>&arr, int s, int e){

    if(s>=e){
        return 0;
    }

    int mid = (s+e)/2;

    int c1 = inversion_count(arr,s,mid);
    int c2 = inversion_count(arr,mid+1,e);
    int ci = merge(arr,s,e);
    return c1+c2+ci;
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
    cout<<inversion_count(arr,s,e)<<endl;
    return 0;
}