#include <iostream>
using namespace std;

int cs(int arr[], int n){
    // write your code here
    if(n==0 || n==1){
        return n;
    }
    int dp[n+1];
    dp[0]=1;
    for(int i=1;i<n+1;i++){
        dp[i]=0;
        for(int j=i-1;j>=0;j--){
            if(j+arr[j]>=i){
                dp[i] += dp[j];
            }
        }
    }
    return dp[n];
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i = 0 ; i < n ;i++){
        cin>>arr[i];
    }
    cout<<cs(arr,n)<<endl;
}
