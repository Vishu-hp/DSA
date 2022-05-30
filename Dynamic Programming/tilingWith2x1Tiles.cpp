#include <iostream>
#include <vector> 

using namespace std ;

    int main() {
        int n ;
        cin>>n ;
       //write your code here
       vector<int>dp(n+1);
       dp[0]=0;
       dp[1]=1;
       dp[2]=2;
       for(int len=3;len<=n;len++){
           dp[len] = dp[len-1]+dp[len-2];
       }
       cout<<dp[n]<<endl;
       return 0;
    }
