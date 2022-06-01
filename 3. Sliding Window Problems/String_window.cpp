#include<bits/stdc++.h>
#include<climits>
#include<string>
using namespace std;

string find_window(string s, string p){ 
    //array as a frequency map or you can use hashmap
    int fp[256] = {0}; //freq pattern
    int fs[256] = {0}; //freq string 

    for(int i=0;i<p.length();i++){
        fp[p[i]]++;
    }

    //sliding window algorithm
    int cnt = 0;
    int start = 0; //left contraction 
    int start_idx = -1; //start_idx for best window
    int min_so_far = INT_MAX; //large number
    int window_size;

    for(int i=0;i<s.length();i++){
        //expand the window by including current character
        char ch = s[i];
        fs[ch]++;

        //count how many characters have been matched till now (string and pattern)
        if(fp[ch]!=0 and fs[ch]<=fp[ch]){
            cnt += 1;
        }

        //another thing 
        //if all character of the pattern are found in the current window then you can start contracting
        if(cnt == p.length()){
            // start contracting from the left to remove unwanted characters(not present in pattern or frequency is higher than required)
            while(fp[s[start]]==0 or fs[s[start]]>fp[s[start]]){
                fs[s[start]]--;
                start++;
            }

            //note the window size
            window_size = i-start+1;
            if(window_size<min_so_far){
                min_so_far = window_size;
                start_idx = start;
            }
        } 
    }
    if(start_idx == -1){
        return "No Window Found";
    }
    return s.substr(start_idx, min_so_far);
}
int main(){
    string s, p;
    cin>>s>>p;

    cout<<find_window(s,p)<<endl;
    return 0;
}