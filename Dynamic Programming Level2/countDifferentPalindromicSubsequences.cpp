class Solution {
public:
    int countPalindromicSubsequences(string s) {
        long long mod = 1e9+7;
        int len=s.length();

        vector<vector<int>>dp(len,vector<int>(len,0));
        vector<int>prev(len);
        unordered_map<char,int>ump;
        prev[0]=-1;
        for(int i=1;i<len;i++){
            char ch=s[i];

            if(ump.find(ch)==ump.end()){
                prev[i]=-1;
            }
            else{
                prev[i] = ump[ch];
            }

            ump[ch]=i;
        }

        ump.clear();
        vector<int>next(len);
        next[len-1]=-1;
        for(int i=len-1;i>=0;i--){
            char ch=s[i];

            if(ump.find(ch)==ump.end()){
                next[i]=-1;
            }
            else{
                next[i] = ump[ch];
            }

            ump[ch]=i;
        }

        for(int g=0;g<len;g++){
            for(int i=0,j=g;j<len;i++,j++){
                if(g==0){
                    dp[i][j]=1;
                }
                else if(g==1){
                    dp[i][j]=2;
                }
                else{
                    char fc = s[i];
                    char lc = s[j];

                    if(fc!=lc){
                        dp[i][j] = ((dp[i][j-1]+dp[i+1][j])%mod - dp[i+1][j-1])%mod;
                    }
                    else{
                        int nextC = next[i];
                        int prevC = prev[j];

                        if(nextC>prevC){
                            dp[i][j] = (2*dp[i+1][j-1]+ 2)%mod;
                        }
                        else if(nextC==prevC){
                            dp[i][j] = (2*dp[i+1][j-1]+1)%mod;
                        }
                        else{
                            dp[i][j] = ((2*dp[i+1][j-1])%mod - dp[nextC+1][prevC-1])%mod;
                        }    
                    }
                }
            }
        }
        if(dp[0][len-1]<0){
            dp[0][len-1] += mod;
        }
        return dp[0][len-1];
    }
};
