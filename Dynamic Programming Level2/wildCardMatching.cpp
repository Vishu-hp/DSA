class Solution {
public:
    bool isMatch(string s1, string s2) {
        int l1=s1.length() , l2=s2.length();
        vector<vector<bool>>dp(l2+1,vector<bool>(l1+1));

        for(int i=l2;i>=0;i--){
            for(int j=l1;j>=0;j--){
                if(i==l2 && j==l1){
                    dp[i][j]=true;
                }
                else if(i==l2){
                    dp[i][j]=false;
                }
                else if(j==l1){
                    if(s2[i]=='*'){
                        dp[i][j] = dp[i+1][j];
                    }
                    else{
                        dp[i][j]=false;
                    }
                }
                else{
                    if(s2[i]=='?'){
                        dp[i][j] = dp[i+1][j+1];
                    }
                    else if(s2[i]=='*'){
                        dp[i][j] = dp[i+1][j] || dp[i][j+1];
                    }
                    else if(s2[i]==s1[j]){
                        dp[i][j]=dp[i+1][j+1];
                    }
                    else{
                        dp[i][j]=false;
                    }
                }
            }
        }
        return dp[0][0];
    }
};
