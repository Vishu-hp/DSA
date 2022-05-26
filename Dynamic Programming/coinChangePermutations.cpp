#include <iostream>
#include <vector>
using namespace std;

int CCP(vector<int> &coins, int amt, vector<int> &dp) {

//  write your code here
  dp[0]=1;
    for(int i=1;i<amt+1;i++){
        for(int j=0;j<coins.size();j++){
          if(i>=coins[j]){
              dp[i] += dp[i-coins[j]];
          }
        }
    }
    return dp[amt];
}

int main() {
  int n;
  cin >> n;
  vector<int> coins(n, 0);
  for (int i = 0; i < coins.size(); i++) {
    cin >> coins[i];
  }
  int amt;
  cin >> amt;
  vector<int> dp(amt + 1, 0);
  CCP(coins, amt, dp);
  cout<<dp[amt]<<endl;
}
