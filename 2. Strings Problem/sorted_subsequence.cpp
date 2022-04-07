#include<bits/stdc++.h>
using namespace std;
void subsequence(string s, string o, vector<string>&v){
    //base case
    if(s.size()==0){
        v.push_back(o);
        return;
    }

    //rec case
    char ch = s[0];
    string reduced_input = s.substr(1);

    //includes 
    subsequence(reduced_input, o + ch, v);

    //excludes
    subsequence(reduced_input, o, v);

}
bool compare(string s1, string s2){
    if(s1.length() == s2.length()){
        return s1<s2;  //dual lexicographical comparision i.e it's sort alpabatically
    }
    return s1.length()<s2.length(); // dual lenght based comparision
}

int main(){
string s;
cin>>s;
vector<string>v;
string output = " ";
subsequence(s,output,v);
sort(v.begin(), v.end(), compare);

for(auto s:v){
    cout<<s<<" , ";
}
return 0;
}