#include<bits/stdc++.h>
using namespace std;

class Pair{
    public:
    int val;
    int i;
    int j;
    string psf;

    Pair(int val,int i,int j,string psf){
        this->val=val;
        this->i=i;
        this->j=j;
        this->psf=psf;
    }
};

void solve(vector<vector<int>>&dp,int n,int m){
    queue<Pair>q;
    q.push(Pair(dp[0][0],0,0,""));
    while(q.size()>0){
        Pair rem=q.front();
        q.pop();

        int x=rem.i,y=rem.j;
        if(x==n-1 && y==m-1){
            cout<<rem.psf<<endl;
        }
        else if(x==n-1){
            q.push(Pair(dp[x][y+1],x,y+1,rem.psf+"H"));
        }
        else if(y==m-1){
            q.push(Pair(dp[x+1][y],x+1,y,rem.psf+"V"));
        }
        else if(dp[x][y+1]<dp[x+1][y]){
            q.push(Pair(dp[x][y+1],x,y+1,rem.psf+"H"));
        }
        else if(dp[x+1][y]<dp[x][y+1]){
            q.push(Pair(dp[x+1][y],x+1,y,rem.psf+"V"));
        }
        else{
            q.push(Pair(dp[x+1][y],x+1,y,rem.psf+"V"));
            q.push(Pair(dp[x][y+1],x,y+1,rem.psf+"H"));
        }
    }
    return;
}

int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>>arr(n,vector<int>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>arr[i][j];
        }
    }

   vector<vector<int>>dp(n,vector<int>(m,0));
   for(int i=n-1;i>=0;i--){
       for(int j=m-1;j>=0;j--){
           if(i==n-1 && j==m-1){
               dp[i][j]=arr[i][j];
           }
           else if(i==n-1){
               dp[i][j] = arr[i][j] + dp[i][j+1];
           }
           else if(j==m-1){
               dp[i][j] = arr[i][j] + dp[i+1][j];
           }
           else{
               dp[i][j] = arr[i][j] + min(dp[i+1][j],dp[i][j+1]);
           }
       }
   }

   cout<<dp[0][0]<<endl;
   solve(dp,n,m);

    return 0;
}
