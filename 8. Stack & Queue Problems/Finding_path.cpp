#include<bits/stdc++.h>
#include<iostream>
#include<string>
#include<sstream>
#include<vector>
using namespace std;
string simplifyPath(string input){
    
    istringstream iss(input);
    vector<string> tokens;
    string token;
    
    //step-1 tokenisation and filtering
    while(getline(iss,token,'/')){
        if(token=="." or token==""){
            continue;
        }
        tokens.push_back(token);
    }

    //step2 handle the used and unused tokens

    vector<string> stack;
    if(input[0]=='/'){ //root directory
        //it's denotes that our path is absolute path.
        stack.push_back("");
    }

    for(string token: tokens){
        if(token==".."){
            //if we get .. then it's contains two cases abs(absolute path) and relative path
            if(stack.size()==0 or stack[stack.size()-1]==".."){
                stack.push_back("..");
            }

            else if(stack[stack.size()-1]!=""){
                stack.pop_back();
            }
        }
        else{
            //x,y,z...
            stack.push_back(token);
        }
    }
    //combine all elements in the satck to get the answer

//for single element
	if(stack.size()==1 and stack[0]==""){
	    return "/";
	}

    ostringstream oss;
    int i = 0;
    for(auto token: stack){
        if(i!=0){
            oss<<"/";
        }
        i++;
        oss<<token;
    }
    return oss.str();
}
int main(){
    int t;
    cin>>t;
    while(t--){
        string input;
        cin>>input;
        cout<<simplifyPath(input)<<endl;
    }
    return 0;
}
