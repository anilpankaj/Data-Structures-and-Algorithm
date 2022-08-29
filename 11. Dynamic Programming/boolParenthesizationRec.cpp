//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int solve(string str, int i, int j,bool istrue){
        //1) base condition
        if(i>j){
            return 0;
        }
        if(i==j){
            if(istrue == true){
                return str[i]==true;
            }
            else{
                return str[i]==false;
            }
        }
        
        // 2) k loop
        int ans = 0;
        for(int k=i+1;k<j;k=+2){
            int lt = solve(str,i,k-1,true);
            int lf = solve(str,i,k-1,false);
            int rt = solve(str,k+1,j,true);
            int rf = solve(str,k+1,j,false);
            
            if(str[k]=='&'){
                if(istrue == true){
                    ans = ans + lt*rt; //true kab dega yeh operator
                }
                else{
                    ans = ans + lf*rt + lt*rf + lf*rf;
                }
            }
            else if(str[k]=='|'){
                if(istrue == true){
                    ans = ans + lt*rt + lt*rf + lf*rt;
                }
                else{
                    ans = ans + lf*rf;
                }
            }
            if(str[k]=='^'){
                if(istrue == true){
                    ans = ans + lt*rf + lf*rt;
                }
                else{
                    ans = ans + lt*rt + lf*rf;
                }
            }
        }
        return ans;
    }
    int countWays(int N, string S){
        // code here
        bool istrue;
        return solve(S,0,S.size()-1,istrue);
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