#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,k;
    cin>>n>>k;
    vector<vector<int>>arr(n,vector<int>(k));
    for(int i=0;i<n;i++){
        for(int j=0;j<k;j++){
            cin>>arr[i][j];
        }
    }

    vector<vector<int>>minCost(n,vector<int>(k));
    int ans = INT_MAX;
    for(int i=0;i<k;i++){
        minCost[n-1][i] = arr[n-1][i];
    }
    for(int i=n-2;i>=0;i--){
        for(int j=0;j<k;j++){
            int minV=INT_MAX;
            for(int x=0;x<k;x++){
                if(j!=x){
                    minV = min(minV,minCost[i+1][x]);
                }
            }
            minCost[i][j] = arr[i][j] + minV; 
            if(i==0){
               ans =min(ans,minCost[i][j]);
            }
        }
    }
    
    cout<<ans<<endl;
        return 0;
}
