#include <iostream>
#include <vector>
using namespace std;

int cs(int arr[], int n, vector<int>& dp) {
  // write your code here
  if(n==0){
    return 0;
  }
  
  dp[0]=0;
  for(int i=1;i<n+1;i++){
    dp[i]=i;
    for(int j=0;j<i;j++){
      if(j+arr[j]>=i){
        dp[i] = min(dp[i],dp[j]+1);
      }
    }
  }
  return dp[n];
}

int main() {
  int n;
  cin >> n;
  int arr[n];
  for (int i = 0 ; i < n ; i++) {
    cin >> arr[i];
  }

  vector<int> dp(n + 1, 0);

  cout << cs(arr, n, dp) << endl;
}
