#include<bits/stdc++.h>
using namespace std;
void replace_space(char *str){
    //1. calc spaces
    int space = 0;
    for(int i=0;str[i]!='\0';i++){ //trace untill getting null
        if(str[i]==' '){
            space += 1;
        }
    }
    //calc indx
    int indx = strlen(str) + 2*space;
    str[indx] = '\0'; //stoping condition 

    for(int i = strlen(str)-1;i>=0;i--){
        if(str[i]==' '){
            str[indx-1] = '0';
            str[indx-2] = '2';
            str[indx-3] = '%';
            indx = indx - 3;
        }
        else{
            str[indx-1] = str[i];
            indx--;
        }
    }
}
int main(){
    char input[10000];
    cin.getline(input,10000);
    replace_space(input);
    cout<<input<<endl;
    return 0;
}