#include<bits/stdc++.h>
#include<cstring>
#include<unordered_map>
#include<iostream>
using namespace std;

string unique_substring(string str){
    int i=0;
    int j=0;
    
    int window_len = 0;
    int max_window_len = 0;
    int start_window = -1;

    //declared unordered map
    unordered_map<char, int>m;

    while(j<str.length()){
        char ch = str[j];
        //if it is inside hashmap & it's idx >= start of the current window
        if(m.count(ch) and m[ch]>=i){ 
            i = m[ch] + 1;
            window_len = j - i; //updated remaining window len excluding current char 
        }
        //update the last occ
        m[ch] = j;
        window_len++;
        j++;

        //update the max_window_len at every step
        if(window_len>max_window_len){
            max_window_len = window_len;
            start_window = i;
        }
    }
    return str.substr(start_window, max_window_len);
}

int main(){
    string input;
    cin>>input;
    cout<<unique_substring(input)<<endl;
    return 0;
}