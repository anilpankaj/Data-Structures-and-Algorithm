#include<bits/stdc++.h>
using namespace std;
int main(){
    string paragraph = "we are learning about STL. STL string class is quite powerful";

    string word;
    getline(cin,word);

    //find function
    int index = paragraph.find(word);

    if(index!=-1){
        cout<<"first occ "<<index<<endl;
    }

    index = paragraph.find(word,index+1);
    
    if(index!=-1){
        cout<<"second occ "<<index<<endl;
    }
//coding challenge: we need to find all accurances of word in the given string

    vector<int>result;
    index = paragraph.find(word);
    while(index!=-1){
        result.push_back(index);
        index = paragraph.find(word,index+1);
    }
    for(int x : result){
        cout<<x<<" ";
    }
    cout<<endl;
    return 0; 
}