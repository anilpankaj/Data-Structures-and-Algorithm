#include<bits/stdc++.h>
using namespace std;

int main(){
    char ch;
    cin>>ch;
    queue<char>q;
    int freq[27] = {0};
    while(ch!='.'){
        //push letter
        q.push(ch);
        //freq count
        freq[ch-'a']++;

        while(!q.empty()){
            int idx = q.front()-'a';
            if(freq[idx]>1){
                q.pop();
            }
            else{
                cout<<q.front()<<endl;
                break;
            }
        }
        if(q.empty()){
            cout<<"-1"<<endl;
        }
        cin>>ch;
    }
    return 0;
}