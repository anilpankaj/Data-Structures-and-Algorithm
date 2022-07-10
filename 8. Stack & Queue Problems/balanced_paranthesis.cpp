#include<bits/stdc++.h>
using namespace std;
bool isbalanced(string str){
    stack<char>s;
    for(auto ch:str){

        switch(ch){
            case '(': 
            case '[':
            case '{': s.push(ch); 
                        break;
            
            case ')': if(!s.empty() and s.top()=='('){
                            s.pop();
                        }
                        else{
                            return false;
                        }
                        break;
            case ']': if(!s.empty() and s.top()=='['){
                            s.pop();
                        }
                        else{
                            return false;
                        }
                        break;
            case '}': if(!s.empty() and s.top()=='{'){
                            s.pop();
                        }
                        else{
                            return false;
                        }
                        break;
            default: continue;
        }
    }
    if(s.empty()){
        return true;
    }
    else{
        return false;
    }
}
int main(){
    string s = "((a+b+c)+[d])";

    if(isbalanced(s)){
        cout<<"balanced paranthesis"<<endl;
    }
    else{
        cout<<"not a balanced paranthesis"<<endl;
    }
    return 0;
}