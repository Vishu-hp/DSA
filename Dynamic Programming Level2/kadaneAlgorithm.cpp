#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    int currSum=arr[0];
    int bestSum=arr[0];
    for(int i=1;i<n;i++){
        if(currSum+arr[i] >arr[i]){
            currSum = currSum+arr[i];
        }
        else{
            currSum = arr[i];
        }

        if(currSum>bestSum){
            bestSum=currSum;
        }
    }

    cout<<bestSum<<endl;
    return 0;
}
