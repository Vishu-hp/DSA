class Solution {
public:
    bool isMatch(string s1, string s2) {
        int l1=s1.length(),l2=s2.length();
        vector<vector<bool>>dp(l2+1,vector<bool>(l1+1));

        for(int i=0;i<l2+1;i++){
            for(int j=0;j<l1+1;j++){
                if(i==0 && j==0){
                    dp[i][j]=true;
                }
                else if(i==0){
                    dp[i][j]=false;
                }
                else if(j==0){
                    if(s2[i-1]=='*'){
                        dp[i][j] = (i-2>=0)?dp[i-2][j]:false;
                    }
                    else{
                        dp[i][j]=false;
                    }
                }
                else{
                    if(s2[i-1]=='.'){
                        dp[i][j] = dp[i-1][j-1];
                    }
                    else if(s2[i-1]=='*'){
                        if(s2[i-2]=='.' || s2[i-2]==s1[j-1]){
                            dp[i][j] = dp[i-2][j] || dp[i][j-1];
                        }
                        else{
                            dp[i][j] = dp[i-2][j];
                        }
                    }
                    else if(s2[i-1]==s1[j-1]){
                        dp[i][j]=dp[i-1][j-1];
                    }
                    else{
                        dp[i][j]=false;
                    }
                }
            }
        }
        return dp[l2][l1];
    }
};
