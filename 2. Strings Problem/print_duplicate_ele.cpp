#include<bits/stdc++.h>
using namespace std;
void dup_str(string str){
    unordered_map<char,int>m;
    for(int i=0;i<str.length();i++){
        m[str[i]]++;
    }

    for(auto x:m){
        cout<<x.first<<" "<<x.second<<endl;
    }
}
int main(){
    string str = "anilpankaj";
    dup_str(str);
    return 0;
}