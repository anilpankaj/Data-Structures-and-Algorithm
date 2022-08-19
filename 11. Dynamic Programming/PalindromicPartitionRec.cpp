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
    int solve(string str, int i, int j){
        //base case
        if(i>=j){
            return 0;
        }
        
        if(isPalindrom(str,i,j)==true){ // if string is already palindrom then we required 0 partition.
            return 0;
        }

        int mn = INT_MAX;
        for(int k=i;k<j;k++){
            int tempans = 1 + solve(str,i,k) + solve(str,k+1,j);
            if(tempans<mn){
                mn = tempans;
            }
        }
        return mn;
    }
    int palindromicPartition(string str)
    {
        // code here
        return solve(str,0,str.size()-1);
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