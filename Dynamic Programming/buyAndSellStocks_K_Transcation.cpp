#include <iostream>
#include <vector>
#include <climits>

using namespace std;

void transactions(vector<int>&arr,int k){
   //write your code here
   int n=arr.size();
   vector<vector<int>>dp(k+1,vector<int>(n));
   for(int i=0;i<n;i++){
      dp[0][i]=0;
   }
   for(int i=1;i<k+1;i++){
      dp[i][0]=0;
   }

   for(int i=1;i<k+1;i++){
      int maxV = INT_MIN;
      for(int j=1;j<n;j++){
            if(dp[i-1][j-1]-arr[j-1] > maxV){
               maxV = dp[i-1][j-1] - arr[j-1];
            }

            if(maxV+arr[j]>dp[i][j-1]){
               dp[i][j] = maxV+arr[j];
            }
            else{
               dp[i][j] = dp[i][j-1]; 
            }
      }
   }
   cout<<dp[k][n-1]<<endl;
   return;
}

int main(){

int n;
cin>>n;
vector<int> arr(n,0);

for (int i = 0; i < n; i++)
{
cin>>arr[i];
}
int k ;
cin>>k;

transactions(arr,k);

   return 0;
}
