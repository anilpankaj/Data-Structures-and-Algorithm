#include<bits/stdc++.h>
using namespace std;
int LongestBand(vector<int>arr){
    int n = arr.size();

    unordered_set<int>s;
    int largest = 1;
    for(int x : arr){
        s.insert(x);
    }

    for(auto elements : s){
        int parent = elements - 1;

        if(s.find(parent)==s.end()){
            int next_num = elements + 1;
            int cnt = 1;

            while(s.find(next_num)!=s.end()){
                next_num++;
                cnt++;
            }

            if(cnt>largest){
                largest = cnt;
            }
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
    cout<<"print the largest band: ";
    cout<<LongestBand(arr)<<endl;
    return 0;
}