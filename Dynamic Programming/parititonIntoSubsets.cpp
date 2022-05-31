#include <bits/stdc++.h>
using namespace std;

long solve(int n,int k){
   if(n==0 || k==0 || k>n){
      return 0;
   }
   if(k==n){
      return 1;
   }
   vector<vector<long>>dp(k+1,vector<long>(n+1,0));
   for(int i=0;i<k+1;i++){
      for(int j=0;j<n+1;j++){
         if(i==0 || j==0){
            dp[i][j]=0;
         }
         else if(i>j){
            dp[i][j]=0;
         }
         else if(i==j){
            dp[i][j]=1;
         }
         else{
            dp[i][j] = dp[i-1][j-1] + dp[i][j-1]*i;
         }
      }
   }
   return dp[k][n];
}

using namespace std ;

   int main() {
      int n ;
      cin>>n ;
      int k ;
      cin>>k ;

     // write your code here
     long ans =solve(n,k);
     cout<<ans<<endl;
   }
