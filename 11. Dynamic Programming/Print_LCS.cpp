#include<bits/stdc++.h>
using namespace std;
void plcs(string s1, string s2, int n, int m){
    int t[n+1][m+1];
    for(int i=0;i<n+1;i++){
        for(int j=0;j<m+1;j++){
            if(i==0 || j==0){
                t[i][j] = 0;
            }
        }
    }

    for(int i=1;i<n+1;i++){
        for(int j=1;j<m+1;j++){
            if(s1[i-1]==s2[j-1]){
                t[i][j] = 1 + t[i-1][j-1];
            }
            else{
                t[i][j] = 0;
            }
        }
    }
    //initialize empty string 
    string res = "";
    int i = n;
    int j = m;
    //let's print lcs string
    while(i>0 && j>0){
        if(s1[i-1]==s2[j-1]){
            res.push_back(s1[i-1]);
            i--;
            j--;
        }
        else{
            if(t[i][j-1]>t[i-1][j]){
                j--;
            }
            else{
                i--;
            }
        }
    }
    for(int i=res.length()-1;i>=0;i--){
        cout<<res[i];
    }
    cout<<endl;
}
int main(){
    string s1,s2;
    cin>>s1>>s2;
    int n = s1.length();
    int m = s2.length();
    plcs(s1,s2,n,m);
    return 0;
}