#include<bits/stdc++.h>
using namespace std;
int main(){
    // int n;
    // cin>>n;
    string s;
    cin>>s;
    /*for(int i=0;i<n;i++){
        cin>>s[i];
    }*/
    map<char, int>m;
    for(int i=0;i<s.size();i++){
        m[s[i]]++;
    }
    map<char, int>::iterator it;
    int cnt=0;
    for(it = m.begin();it!=m.end();it++){
        cout<<(*it).first<<" "<<(*it).second<<endl;
    }
    cout<<"output: "<<endl;
    for(it = m.begin();it!=m.end();it++){
        if((*it).second==1){
            cout<<(*it).first<<" "<<(*it).second<<endl;
            break;
        }else{
            cnt++;
        }
    }
    if(cnt==m.size()){
        cout<<(*it).first<<" "<<(*it).second<<endl;
    }
    return 0;
}