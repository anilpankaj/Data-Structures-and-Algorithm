#include<bits/stdc++.h>
using namespace std;
int main(){
    string input;
    getline(cin,input);
    //"this is a gateguide students platform"

    //create a string stream object
    stringstream ss(input);
    //it's support >> and << operators

    string token;
    vector<string>tokens;

    while(getline(ss,token,' ')){ // read from the ss object, store inside the token, Delimiter(we can use anything like- '','a',',')
        tokens.push_back(token);
    }

    //print all tokens
    for(auto token: tokens){
        cout<<token<<",";
    }
    return 0;
}