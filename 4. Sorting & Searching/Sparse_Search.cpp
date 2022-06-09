#include<bits/stdc++.h>
using namespace std;
int sparse_search(string arr[], int n, string key){
    int s = 0;
    int e = n-1;
    //cout<<"anil"<<endl;
    while(s<=e){
        //cout<<"anil1"<<endl;
        int mid = (s+e)/2;
        int mid_left = mid-1;
        int mid_right = mid+1;

        if(arr[mid]==""){
            //update our mid to point to a nearest non empty string
            //cout<<"anil2"<<endl;
            while(1){
                if(mid_left<s and mid_right>e){
                    return -1;
                }
                else if(mid_right<=e and arr[mid_right]!=""){
                    mid = mid_right;
                    //cout<<"anilpankaj"<<endl;
                    break;
                }
                else if(mid_left>=s and arr[mid_left]!=""){
                    mid = mid_left;
                    break;
                }
                mid_left--;
                mid_right++;
            }
        }
        if(arr[mid]==key){
            return mid;
        }
        else if(arr[mid]>key){
            e = mid - 1;
        }
        else{
            s = mid + 1;
        } 
    }
    return -1;
}
int main(){
    string a[] = {"ai", "", "", "bat", "", "", "car", "cat", "", "", "dog", "e"};
    int n = 12;
    string f;
    cin>>f;
    cout<<sparse_search(a,n,f)<<endl;
    return 0;
}