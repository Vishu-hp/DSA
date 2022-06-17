#include<bits/stdc++.h>
using namespace std;

void solve(string str){
    vector<long>dp(str.length()+1);
    dp[0]=1;
    unordered_map<char,int>ump;

    for(int i=1;i<str.length()+1;i++){
        dp[i] = 2*dp[i-1];
        char ch=str[i-1];
        if(ump.find(ch) != ump.end()){
            int j=ump[ch];
            dp[i]=dp[i]-dp[j-1];
        }
        ump[ch]=i;
    }
    cout<<dp[str.length()]-1<<endl;
    return;
}

int main(){
    string str;
    cin>>str;

    solve(str);
    return 0;
}
