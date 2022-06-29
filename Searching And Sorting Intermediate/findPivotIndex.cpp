#include <iostream>
#include <vector>

using namespace std;

int pivotIdx(vector<int>& arr){
    // write your code here
    int ans=-1;
    int pSum=0;
    int sumArr = 0;
    for(int i=0;i<arr.size();i++){
        sumArr += arr[i];
    }
    int lSum,rSum;
    for(int i=0;i<arr.size();i++){
        pSum += arr[i];
        
        lSum = pSum-arr[i];
        rSum = sumArr-pSum;
        if(lSum==rSum){
            return i;
        }
    }

    return ans;
}

int main(){
    int n;
    cin >> n;
    
    vector<int> arr(n,0);
    
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    int pi = pivotIdx(arr);
    cout << pi;
    
    return 0;
}
