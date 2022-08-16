#include<bits/stdc++.h>
using namespace std;
void scs(string s1, string s2, int n, int m){
    int t[n+1][m+1];
    for(int i=0;i<n+1;i++){
        for(int j=0;j<m+1;j++){
            if(i==0 || j==0){
                t[i][j] = 0;
            }
        }
    }
    //int res = 0;
    for(int i=0;i<n+1;i++){
        for(int j=0;j<m+1;j++){
            if(s1[i-1]==s2[j-1]){
                t[i][j] = 1 + t[i-1][j-1];
                //res = max(res,t[i][j]);
            }
            else{
                t[i][j] = max(t[i][j-1], t[i-1][j]);
            }
        }
    }
    string s = "";
    int i = n;
    int j = m;
    while(i>0 && j>0){
        if(s1[i-1]==s2[j-1]){
            s.push_back(s1[i-1]);
            i--;
            j--;
        }
        else{
            if(t[i][j-1]>t[i-1][j]){
                s.push_back(s2[j-1]);
                j--;
            }
            else if(t[i-1][j]>t[i][j-1]){
                s.push_back(s1[i-1]);
                i--;
            }
        }
    }
    //if i==0 or j==0 then put rest string in resultant string
    while(i>0){
        s.push_back(s1[i-1]);
        i--;
    }
    while(j>0){
        s.push_back(s2[j-1]);
        j--;
    }
    for(int i=s.length()-1;i>=0;i--){
        cout<<s[i];
    }
    cout<<endl;
}
int main(){
    string s1,s2;
    cin>>s1>>s2;
    int n = s1.length();
    int m = s2.length();
    scs(s1,s2,n,m);
    return 0;
}