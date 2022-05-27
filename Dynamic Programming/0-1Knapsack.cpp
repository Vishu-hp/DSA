#include <iostream>
#include <vector>

using namespace std;

void zeroOneKnapsack(int n,vector<int> &val, vector<int> &weight,int cap){
 
//  write your code here
  vector<vector<int>>dp(n+1,vector<int>(cap+1));

  for(int i=0;i<cap+1;i++){
    dp[0][i] = 0;
  }
  for(int i=1;i<n+1;i++){
    dp[i][0]=0;
  }

  for(int i=1;i<n+1;i++){
    for(int j=1;j<cap+1;j++){
      if(j>=weight[i-1]){
        dp[i][j] = max(dp[i-1][j],dp[i-1][j-weight[i-1]]+val[i-1]);
      }
      else{
        dp[i][j] = dp[i-1][j];
      }
    }
  }
  cout<<dp[n][cap]<<endl;
  return;
}

int main() {
    
  int n;
  cin >> n;
  
  vector<int> val(n);
  for (int i = 0; i < n; i++) {
    cin >> val[i];
  }
  
  vector<int> weight(n);
  for (int i = 0; i < n; i++) {
    cin >> weight[i];
  }
  
  int cap;
  cin >> cap;
  
  zeroOneKnapsack(n,val,weight,cap);


}
