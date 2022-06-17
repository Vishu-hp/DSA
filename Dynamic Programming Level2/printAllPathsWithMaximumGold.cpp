#include<bits/stdc++.h>
using namespace std;

class Pair{
    public:
    int i,j;
    string psf;

    Pair(int i,int j,string psf){
        this->i=i;
        this->j=j;
        this->psf=psf;
    }
};

int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>>arr(n,vector<int>(m,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>arr[i][j];
        }
    }

    vector<vector<int>>dp(n,vector<int>(m,0));

    for(int j=m-1;j>=0;j--){
        for(int i=0;i<n;i++){
            if(j==m-1){
                dp[i][j] = arr[i][j];
            }
            else if(i==0){
                dp[i][j]= arr[i][j] + max(dp[i][j+1],dp[i+1][j+1]);
            }
            else if(i==n-1){
                dp[i][j]= arr[i][j] + max(dp[i][j+1],dp[i-1][j+1]);
            }
            else{
                dp[i][j] = arr[i][j] + max(dp[i][j+1],max(dp[i-1][j+1],dp[i+1][j+1]));
            }
        }
    }
    
    int maxGold=0;
    for(int i=0;i<n;i++){
        if(dp[i][0]>maxGold){
            maxGold=dp[i][0];
        }
    }
    cout<<maxGold<<endl;
    queue<Pair>q;
    for(int i=0;i<n;i++){
        if(dp[i][0]==maxGold){
            q.push(Pair(i,0,to_string(i)+" "));
        }
    }

    while(q.size()>0){
        Pair rem=q.front();
        q.pop();

        int i=rem.i;
        int j=rem.j;
        if(j==m-1){
            cout<<rem.psf<<endl;
        }
        else if(i==0){
            int g = max(dp[i][j + 1], dp[i + 1][j + 1]);


            if (g == dp[i][j + 1]) {
            q.push(Pair(rem.i, rem.j + 1,rem.psf + "d2 "));
            }

            if (g == dp[i + 1][j + 1]) {
            q.push(Pair(i + 1, j + 1,rem.psf + "d3 "));
            }
        }
        else if(i==n-1){
            int g = max(dp[i][j + 1], dp[i -1][j + 1]);


            if (g == dp[i][j + 1]) {
            q.push(Pair(rem.i, rem.j + 1,rem.psf + "d2 "));
            }

            if (g == dp[i - 1][j + 1]) {
            q.push(Pair(rem.i - 1, rem.j + 1,rem.psf + "d1 "));
            }
        }
        else{
            int g = max(dp[rem.i][rem.j + 1], max(dp[rem.i - 1][rem.j + 1], dp[rem.i + 1][rem.j + 1]));

            if (g == dp[rem.i - 1][rem.j + 1]) {
                q.push(Pair(rem.i - 1, rem.j + 1,rem.psf + "d1 "));
            }

            if (g == dp[rem.i][rem.j + 1]) {
            q.push(Pair(rem.i, rem.j + 1,rem.psf + "d2 "));
            }

            if (g == dp[rem.i + 1][rem.j + 1]) {
            q.push(Pair(rem.i + 1, rem.j + 1,rem.psf + "d3 "));
            }
        }
    }
    return 0;
}
