//{ Driver Code Starts
// Initial Template for c++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    bool isPalindrom(string str, int i, int j){
        while(i<j){
            if(str[i]!=str[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    int solve(string str, int i, int j, vector<vector<int>>&t){
        //base case
        if(i>=j){
            return 0;
        }
        
        if(isPalindrom(str,i,j)==true){ // if string is already palindrom then we required 0 partition.
            return 0;
        }
        
        // if t[i][j] !=-1 then we return that value
        if(t[i][j]!=-1){
            return t[i][j];
        }
        
        int mn = INT_MAX;
        for(int k=i;k<j;k++){
            int tempans = 1 + solve(str,i,k,t) + solve(str,k+1,j,t);
            if(tempans<mn){
                mn = tempans;
            }
        }
        t[i][j] = mn;
        return t[i][j];
    }
    int palindromicPartition(string str)
    {
        // code here
        int n = str.size();
        vector<vector<int>>t(n+1, vector<int>(n+1,-1));
        return solve(str,0,n-1,t);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        
        Solution ob;
        cout<<ob.palindromicPartition(str)<<"\n";
    }
    return 0;
}
// } Driver Code Ends