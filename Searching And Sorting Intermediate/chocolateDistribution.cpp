#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int chocolatedistribution(vector<int> &arr,int m){
    // write your code here
    sort(arr.begin(),arr.end());

    int ans=INT_MAX;
    for(int i=0;i<=arr.size()-m;i++){
        int minW = arr[i];
        int maxW = arr[i+m-1];
        ans = min(ans,maxW-minW);
    }
    return ans;
}

int main(){
    int n;
    cin>>n;

    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int m;
    cin>>m;

    cout<<chocolatedistribution(arr,m)<<endl;
    return 0;
}
