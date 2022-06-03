#include<bits/stdc++.h>
using namespace std;

string psf;
void dfs(vector<vector<int>>&arr,int r,int c,vector<vector<bool>>&vis ){
    vis[r][c]=true;

    if(r-1>=0 && arr[r-1][c]==1 &&vis[r-1][c]==false){
        psf+= "t";
        dfs(arr,r-1,c,vis);
        psf+= "z";
    }
    if(c-1>=0 && arr[r][c-1]==1 &&vis[r][c-1]==false){
        psf+= "l";
        dfs(arr,r,c-1,vis);
        psf+= "z";
    }
    if(r+1<arr.size() && arr[r+1][c]==1 &&vis[r+1][c]==false){
        psf+= "d";
        dfs(arr,r+1,c,vis);
        psf+= "z";
    }
    if(c+1<arr[0].size() && arr[r][c+1]==1 &&vis[r][c+1]==false){
        psf+= "r";
        dfs(arr,r,c+1,vis);
        psf+= "z";
    }
    return;
}

int numDistinctIslands(vector<vector<int>>& arr){
    //write your code here
    int m=arr.size();
    int n=arr[0].size();
    int cnt=0;
    unordered_set<string>ust;
    vector<vector<bool>>vis(m,vector<bool>(n,false));
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(arr[i][j]==1 && vis[i][j]==false){
                psf="x";
                dfs(arr,i,j,vis);
                ust.insert(psf);
            }
        }
    }
    return ust.size();
}

int main(){
    int n,m;
    cin>>n>>m;
    
    vector<vector<int>>arr(n,vector<int>(m));
    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            int x;
            cin>>x;
            
            arr[i][j]=x;
        }
    }
    cout<<numDistinctIslands(arr)<<endl;;
}
