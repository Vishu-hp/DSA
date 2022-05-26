#include <bits/stdc++.h>

using namespace std;


int collectGold(int n, int m, vector<vector<int>>& arr, vector<vector<int>>& dp) {

    //write your code here
    int ans=INT_MIN;
    
    for(int row=0;row<n;row++){
      dp[row][m-1] = arr[row][m-1];
    }

    for(int col=m-2;col>=0;col--){
      for(int row=0;row<n;row++){
        if(row==0){
          dp[row][col] = max(dp[row][col+1],dp[row+1][col+1])+arr[row][col];
        }
        else if(row==n-1){
          dp[row][col] = max(dp[row][col+1],dp[row-1][col+1])+arr[row][col];
        }
        else{
          dp[row][col] = max(dp[row][col+1],max(dp[row-1][col+1],dp[row+1][col+1]))+arr[row][col];
        }

        if(col==0){
          ans = max(ans,dp[row][col]);
        }
      }
    }
  return ans;
}



int main() {
  int n, m;
  cin >> n >> m;

  vector<vector<int>> arr(n, vector<int>(m, 0));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> arr[i][j];
    }
  }

  vector<vector<int>> dp(n, vector<int>(m, 0));

  cout << collectGold(n, m, arr, dp);

}
