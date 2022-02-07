#include<bits/stdc++.h>
using namespace std;

int countminswap(vector<int>arr){
    int n = arr.size();
    int ans = 0;

    //know the actual positions of the elements(sorting)
    //store the current indices
    pair<int,int>ap[n];
    for(int i=0;i<n;i++){
        ap[i].first = arr[i];
        ap[i].second = i;
    }

    //sorting
    sort(ap, ap+n);

    //build main logic
    vector<bool>visited(n,false);

    for(int i=0;i<n;i++){

        //if element is visited or element is in right position
        //then don't do anything for that element.
        int old_position = ap[i].second;
        if(visited[i]==true or old_position == i){
            continue;
        }

        //visiting the element(index) for first time
        int node = i;
        int cycle = 0;
        while (!visited[node])
        {
            visited[node] = true;
            int next_node = ap[node].second;
            node = next_node;
            cycle += 1;
        }
        ans += (cycle-1);
    }

    return ans;
}
int main(){
    int n;
    cin>>n;
    vector<int>arr;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        arr.push_back(x);
    }
    cout<<countminswap(arr)<<endl;
    return 0;
}