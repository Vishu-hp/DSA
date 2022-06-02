#include<bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>>&arr,int r,int c){
    arr[r][c]=0;

    if(r-1>=0 && arr[r-1][c]==1){
        dfs(arr,r-1,c);
    }
    if(c-1>=0 && arr[r][c-1]==1){ 
        dfs(arr,r,c-1);
    }
    if(r+1<arr.size() && arr[r+1][c]==1){
        dfs(arr,r+1,c);
    }
    if(c+1<arr[0].size() && arr[r][c+1]==1){
        dfs(arr,r,c+1);
    }
    return;
}

int numEnclaves(vector<vector<int>>& arr){
    int m=arr.size();
    int n=arr[0].size();

    //first row
    for(int i=0;i<n;i++){
        if(arr[0][i]==1){
            dfs(arr,0,i);
        }
    } 

    // first col
    for(int i=0;i<m;i++){
        if(arr[i][0]==1){
            dfs(arr,i,0);
        }
    }

    //last row
    for(int i=0;i<n;i++){
        if(arr[m-1][i]==1){
            dfs(arr,m-1,i);
        }
    } 

    // last col
    for(int i=0;i<m;i++){
        if(arr[i][n-1]==1){
            dfs(arr,i,n-1);
        }
    }

    int ans=0;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(arr[i][j]==1){
                ans++;
            }
        }
    }
    return ans;
}

int main(){
    int m,n;
    cin>>m>>n;
    
    vector<vector<int>>arr(m,vector<int>(n));
    
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            int x;
            cin>>x;
            arr[i][j]=x;
        }
    }
    
    cout<<numEnclaves(arr)<<endl;
}
