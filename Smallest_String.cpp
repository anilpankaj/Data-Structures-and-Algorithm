#include<bits/stdc++.h>
using namespace std;

bool compare(string s1, string s2){
    return s1 + s2 < s2 + s1;
}
int main(){
    /*string arr[] = {"a","ab","aba"};
    int n = 3;*/

    int n;
    cin>>n;
    string *s = new string[n];

    for(int i=0;i<n;i++){
        cin>>s[i];
    }
    
    sort(s, s+n, compare);
    
    for(int i=0;i<n;i++){
        cout<<s[i];
    }
    cout<<endl;
    return 0;
}