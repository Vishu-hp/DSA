#include<bits/stdc++.h>
using namespace std;

int main(){
    string str;
    cin>>str;

    vector<vector<int>>dp(str.length()+1,vector<int>(str.length()+1));
    for(int i=0;i<str.length()+1;i++){
        for(int j=0;j<str.length()+1;j++){
            if(i==0 || j==0){
                dp[i][j]=0;
            }
            else if(str[i-1]==str[j-1] && i!=j){
                dp[i][j] = 1+dp[i-1][j-1];
            }
            else{
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    cout<<dp[str.length()][str.length()]<<endl;;
    return 0;
}
