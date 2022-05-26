#include <iostream>
#include <vector>
using namespace std;

int coinchangecombination(vector<int> &coins, int amt, vector<int> &dp) {
 
//  write your code here
    dp[0]=1;
    for(int i=0;i<coins.size();i++){
        for(int j=1;j<amt+1;j++){
            if(j-coins[i]>=0){
                dp[j] += dp[j-coins[i]];
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
  coinchangecombination(coins, amt, dp);
  cout<<dp[amt]<<endl;  
}
