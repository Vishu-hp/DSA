#include <iostream>
#include <vector>

using namespace std;



int minCost(int n, int m, vector<vector<int>> &arr, vector<vector<int>> &dp ){
    
    // write your code here
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      if(i==0 && j==0){
        dp[i][j]=arr[i][j];
      }
      else if(i==0){
        dp[i][j] = dp[i][j-1]+arr[i][j];
      }
      else if(j==0){
        dp[i][j] = dp[i-1][j] + arr[i][j];
      }
      else{
        dp[i][j] = min(dp[i-1][j],dp[i][j-1])+arr[i][j];
      }
    }
  }

  return dp[n-1][m-1];
  
}

int main()  {

  int n;
  int m;

  cin >> n >> m;
  
  vector<vector<int>> arr(n, vector<int>(m));		

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> arr[i][j];
    }
  }
  
  vector<vector<int>> dp(n, vector<int>(m));		

  cout << minCost(n, m, arr, dp)<<endl;
}
