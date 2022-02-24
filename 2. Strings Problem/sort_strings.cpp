#include<bits/stdc++.h>
using namespace std;

string ExtractStringATkey(string str, int key){
    //string tokeniser
    
    char *s = strtok((char*)str.c_str(), " ");
    while(key>1){
        s = strtok(NULL, " ");
        key--;
    }
    return (string)s;
}

int convertToint(string s){
    int ans = 0;
    int p = 1;
    for(int i = s.length()-1;i>=0;i--){
        ans += ((s[i]-'0')*p);
        p = p*10;
    }
    return ans;
}

bool lexicoCompare(pair<string, string>s1, pair<string, string>s2){
    string key1, key2;
    key1 = s1.second;
    key2 = s2.second;

    return key1<key2;
}

bool numericComapare(pair<string, string>s1, pair<string, string>s2){
    string key1, key2;
    key1 = s1.second;
    key2 = s2.second;

    return convertToint(key1)<convertToint(key2);
}

int main(){
    int n;
    cin>>n;

    cin.get();  //consume the extra \n in input

    string temp;
    vector<string>v;

    for(int i=0;i<n;i++){
        getline(cin,temp); //include white space
        v.push_back(temp);
    }

    int key;
    string reversal, ordering;
    cin>>key>>reversal>>ordering;  //Doesn't include white space


    //1. To extract keys for comparison & store them
    vector<pair<string,string>>vp;
    for(int i=0;i<n;i++){
        vp.push_back({v[i], ExtractStringATkey(v[i],key)});
    }


    //2. Sorting 
    if(ordering=="numeric"){
        sort(vp.begin(), vp.end(), numericComapare);
    }
    else{
        sort(vp.begin(), vp.end(), lexicoCompare);
    }


    //3. Reversal
    if(reversal=="true"){
        reverse(vp.begin(), vp.end());
    }


    //4. Output
    for(int i=0;i<n;i++){
        cout<<vp[i].first<<endl;
    }

    return 0;
}