#include<bits/stdc++.h>
using namespace std;
void find_permutations(string str, int i, int n){
    //base case
    if(i==n-1){
        cout<<str<<endl;
        return;
    }

    //process each character of the remaining string
    for(int j=i;j<n;j++){
        //swap character at index 'i' with the current character
        swap(str[i],str[j]); // stl swap() used

        //recursion for substring str[i+1,n-1]
        find_permutations(str, i+1, n);

        //backtracking(restore the string to it's original state)
        swap(str[i],str[j]);
    }
}
int main(){
    string s;
    cin>>s;
    find_permutations(s,0,s.length());
    return 0;
}