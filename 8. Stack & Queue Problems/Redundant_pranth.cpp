#include<bits/stdc++.h>
using namespace std;
bool isRedundant(string str){
    stack<char>s;
    for(auto ch:str){
        if(ch!=')'){
            s.push(ch);
        }
        else{
            bool opr = false;
            while(!s.empty() and s.top()!='('){
                char tp = s.top();
                if(tp=='+' or tp=='-' or tp=='*' or tp=='/'){
                    opr = true;
                } 
                s.pop();
            }
            s.pop(); //pop after the loop 
            if(opr==false){
                return true;
            }
        }
    }
    return false;
}
int main(){
    string s = "(a+b+(c*d))";
    if(isRedundant(s)){
        cout<<"redundant"<<endl;
    }
    else{
        cout<<"not redundant"<<endl;
    }
    return 0;
}