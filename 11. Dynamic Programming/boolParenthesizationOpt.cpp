//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<vector<vector<int>>>t;
    const int mod = 1003;
    int countWays(int n, string S){
        // code here
        t.resize(n+1,vector<vector<int>>(n+1,vector<int>(2,-1))); //(n+1)*(n+1)*2
        int i=0;
        int j=n-1;
        bool istrue = true; // current state
        return solve(S,i,j,istrue);
    }
    
    int solve(string &s, int i, int j, bool istrue){
        //base condition
        if(i>j){ // empty string 
            return 0;
        }
        if(i==j){ // 1 length string
            if(istrue==true){
                if(s[i]=='T'){
                    return 1;
                }
                else{
                    return 0;
                }
            }
            if(istrue==false){
                if(s[i]=='F'){
                    return 1;
                }
                return 0;
            }
        }
        if(t[i][j][istrue]!=-1){
            return t[i][j][istrue];
        }
        int ways = 0;
        for(int k=i+1;k<j;k+=2){
            int lt = solve(s,i,k-1,true);
            int rt = solve(s,k+1,j,true);
            int lf = solve(s,i,k-1,false);
            int rf = solve(s,k+1,j,false);
            if(s[k]=='&'){
                if(istrue){
                    ways+=(lt*rt)%mod;
                }
                if(!istrue){
                    ways+=(lt*rf)%mod + (lf*rt)%mod + (lf*rf)%mod;
                }
            }
            else if(s[k]=='|'){
                if(istrue){
                    ways += (lt*rt)%mod + (lt*rf)%mod + (lf*rt)%mod;
                }
                if(!istrue){
                    ways += (lf*rf)%mod;
                }
            }
            else if(s[k]=='^'){
                if(istrue){
                    ways += (lt*rf)%mod + (lf*rt)%mod;
                }
                if(!istrue){
                    ways += (lt*rt)%mod + (lf*rf)%mod;
                }
            }
        }
        t[i][j][istrue] = ways%mod;
        return ways%mod;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        string S;
        cin>>S;
        
        Solution ob;
        cout<<ob.countWays(N, S)<<"\n";
    }
    return 0;
}
// } Driver Code Ends