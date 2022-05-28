#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<vector<int>>arr(n,vector<int>(3));
    for(int i=0;i<n;i++){
        for(int j=0;j<3;j++){
            cin>>arr[i][j];
        }
    }

    vector<vector<int>>minCost(n,vector<int>(3));
    minCost[n-1][0] = arr[n-1][0];
    minCost[n-1][1] = arr[n-1][1];
    minCost[n-1][2] = arr[n-1][2];
    for(int i=n-2;i>=0;i--){
        minCost[i][0] = arr[i][0] + min(minCost[i+1][1],minCost[i+1][2]);
        minCost[i][1] = arr[i][1] + min(minCost[i+1][0],minCost[i+1][2]);
        minCost[i][2] = arr[i][2] + min(minCost[i+1][0],minCost[i+1][1]);
    }
    int ans = min(minCost[0][0],min(minCost[0][1],minCost[0][2]));
    cout<<ans<<endl;
        return 0;
}
