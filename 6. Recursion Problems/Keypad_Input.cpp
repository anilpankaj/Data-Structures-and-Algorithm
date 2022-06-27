#include<bits/stdc++.h>
using namespace std;

string keypad[] = {"","","ABC","DEF","GHI","JKL","MNO","PQRS","TUV","WXYZ"};

void PrintKeyPadOutput(string input, string output, int i=0){

    if(input[i]=='\0'){
        cout<<output<<endl;
        return;
    }

    // recursive case
    int current_digit = input[i]-'0'; //convert char to int
    if(current_digit==0 or current_digit==1){
        PrintKeyPadOutput(input,output,i+1);
    }

    //keypad
    for(int k=0;k<keypad[current_digit].size();k++){
        PrintKeyPadOutput(input,output + keypad[current_digit][k], i+1);
    }
    return;

}
int main(){
    string input;
    cin>>input;
    string output;
    PrintKeyPadOutput(input,output);
    return 0;
}