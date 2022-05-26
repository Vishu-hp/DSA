#include <bits/stdc++.h>
using namespace std;
void input(vector<int> &arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        cin >> arr[i];
    }
}
void targetSumPair(vector<int> &arr, int target)
{
    //write your code here
    int n=arr.size();
    vector<vector<bool>>dp(n+1,vector<bool>(target+1));
    dp[0][0]=true;
    for(int i=1;i<target+1;i++){
        dp[0][i]=false;
    }

    for(int i=1;i<n+1;i++){
        dp[i][0]=true;
    }

    for(int i=1;i<n+1;i++){
        for(int j=1;j<target+1;j++){
            if(j-arr[i-1]>=0){
                dp[i][j] = dp[i-1][j] || dp[i-1][j-arr[i-1]];
            }
            else{
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    if(dp[n][target]){
        cout<<"true"<<endl;
    }
    else{
        cout<<"false"<<endl;
    }
    return;
}
int main()
{
    int n, target;
    cin >> n;
    vector<int> vec(n, 0);
    input(vec);
    cin >> target;
    targetSumPair(vec, target);
    return 0;
}
