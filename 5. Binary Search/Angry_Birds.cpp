#include<bits/stdc++.h>
using namespace std;
bool canPlaceBirds(int B, int n, vector<int>nests, int dis){
    int birds = 1;
    int location = nests[0];

    // To travers another birds
    for(int i=1;i<n;i++){
        int curr_loc = nests[i];
        if(curr_loc-location>=dis){
            birds++;
            location = curr_loc;
            if(birds==B){
                return true;
            }
        }
    }
    return false;
}
int main(){
    int n;
    cin>>n;
    vector<int>nests;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        nests.push_back(x);
    }
    int B; // birds
    cin>>B;

    //sorting to apply binary search algo.
    sort(nests.begin(), nests.end());

    //Binary Search
    int s = 0;
    int e = nests[n-1] - nests[0];
    int res = -1;

    while(s<=e){
        int mid = (s+e)/2;

        bool canPlace = canPlaceBirds(B,n,nests,mid); //checking, can we place birds or not?

        if(canPlace){
            res = mid;
            s = mid + 1;
        }
        else{
            e = mid - 1;
        }
    }
    cout<<res<<endl;
    return 0;
}