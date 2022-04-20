#include<bits/stdc++.h>
using namespace std;
void housing_fxn(vector<int>plots, int k, int n){
    int cs = 0;
    int i = 0; 
    int j = 0;
    int s;
    int smallest_window = INT_MAX;
    while(j<n){
        //expand to right
        cs += plots[j];
        j++;
        //remove elements from the left till cs>sum and i<j
        while(cs>k && i<j){
            //if we have negative interger
            if(plots[i]<0){
                cs += plots[i];
                i++;
            }
            cs = cs - plots[i];
            i++;
            
        }
        //check if any given points
        if(cs == k){
            //print the windows
            cout<<i<<" - "<<j-1<<endl;

            //for calculating smallest window whos contains required sum
            s = j-i-1;
            smallest_window = min(smallest_window, s);
        }
    }
    cout<<"smallest window: "<<smallest_window<<endl;
    return;
}
int main(){
    int n;
    cin>>n;
    vector<int>plots;
    int k;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        plots.push_back(x);
    }
    cin>>k;
    housing_fxn(plots,k,n);
    return 0;
}