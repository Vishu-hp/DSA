#include<iostream>
using namespace std;

int solve(int n){
    if(n==0){
        return 1;
    }
    else if(n<0){
        return 0;
    }

    int dp[n+1];
    dp[0]=1;
    for(int i=1;i<=n;i++){
        if(i>=3){
            dp[i] = dp[i-1]+dp[i-2]+dp[i-3];
        }
        else if(i>=2){
            dp[i] = dp[i-1]+dp[i-2];
        }
        else{
            dp[i]=dp[i-1];
        }
    }
    return dp[n];
}

int main() {
    int n;
    cin>>n;

    int ans = solve(n);
    cout<<ans<<endl;
    return 0;
}
