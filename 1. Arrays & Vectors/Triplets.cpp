#include<bits/stdc++.h>
using namespace std;
vector<vector<int>>find_Triplets(vector<int>arr, int sum){
    //sort array
    sort(arr.begin(), arr.end());
    //iterate with two pointer approach
    vector<vector<int>>result;
    int n = arr.size();
    int s;
    int e;

    //no use of executing solution if n<3
    if(n<3){
        return {};
    }

    // n-2 to skiping out of range
    for(int i=0;i<n-2;i++){
        
        //remove duplicate i values
        if(i==0 || arr[i]!=arr[i-1]){
            s = i+1;
            e = n-1;
            //not overlap or stoping condition
            while(s<e){
                int currunt_sum = arr[i];
                currunt_sum += arr[s];
                currunt_sum += arr[e];
                
                if(currunt_sum==sum){
                    result.push_back({arr[i],arr[s],arr[e]});

                    //if we find some duplicates then skip it.
                    while(s<e && arr[s]==arr[s+1]){
                        s++;
                    }
                    while(s<e && arr[e]==arr[e-1]){
                        e--;
                    }

                    //if no duplicate then inc/dec.
                    s++;
                    e--;
                }
                else if(currunt_sum>sum){
                    e--;
                }
                else{
                    s++;
                }
            }
        }
        
    }     
    return result;
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
    int s;
    cout<<"enter the element who's sum is equal to triplet"<<endl;
    cin>>s;
    auto p = find_Triplets(arr,s);
    for(auto v : p){
        for(auto no : v){
            cout<<no<<",";
        }
        cout<<endl;
    }
    return 0;
}