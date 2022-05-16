#include <bits/stdc++.h>

using namespace std;

void dfs(vector<vector<int>>&arr,vector<vector<bool>>&vis,int srci,int srcj,int n,int m){
    if(!(srci>=0 && srcj>=0 && srci<n && srcj<m && arr[srci][srcj]==0 && vis[srci][srcj]==false)){
        return;
    }
    vis[srci][srcj]=true;
    dfs(arr,vis,srci-1,srcj,n,m);
    dfs(arr,vis,srci,srcj+1,n,m);
    dfs(arr,vis,srci+1,srcj,n,m);
    dfs(arr,vis,srci,srcj-1,n,m);
}

int main()
{
    int n, m;
    cin >> n;
    cin >> m;

    vector<vector<int>> arr;

    for (int i = 0; i < n; i++)
    {
        vector<int> ans;
        for (int j = 0; j < m; j++)
        {
            int res;
            cin >> res;
            ans.push_back(res);
        }
        arr.push_back(ans);
    }

    //write your code here
    vector<vector<bool>>vis(n,vector<bool>(m,false));
    int cnt=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(arr[i][j]==0 && vis[i][j]==false){
                dfs(arr,vis,i,j,n,m);
                cnt++;
            }
        }
    }
    cout<<cnt<<endl;
    return 0;
}
