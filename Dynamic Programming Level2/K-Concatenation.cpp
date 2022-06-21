class Solution {
public:
            const int mod = 1e9+7;

    int kadane(vector<int>&arr){
        long long  currSum=arr[0];
        long long maxSum = arr[0];

        for(int i=1;i<arr.size();i++){
            if(currSum+arr[i] > arr[i]){
                currSum = (currSum + arr[i]);
            }
            else{
                currSum = arr[i];
            }

            if(currSum>maxSum){
                maxSum = currSum;
            }
        }
        return maxSum;
}

int kadaneTwoCopies(vector<int>&arr){
    vector<int>nArr(arr.size()*2);
    for(int i=0;i<arr.size();i++){
        nArr[i]=arr[i];
        nArr[i+arr.size()]=arr[i];
    }

    return kadane(nArr);
}
    
    int kConcatenationMaxSum(vector<int>& arr, int k) {
        long long sum=0;
        for(int i=0;i<arr.size();i++){
            sum = (sum + arr[i]);
        }
         long long ans;
         if(k==1){
            ans = kadane(arr);
        }
        else{
            if(sum<0){
                ans = kadaneTwoCopies(arr);
            }
            else{
                ans = (kadaneTwoCopies(arr) + ((long long)(k-2)*(long long)sum));
            }
        }
        if(ans<0){
            return 0;
        }
        if(ans>mod){
            ans = ans%mod;
        }
        return ans;
    }
};
