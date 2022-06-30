class Solution {
public:
    bool isPossAns(vector<int>&arr,int k,int h){
        long long time=0;
        for(int i=0;i<arr.size();i++){
            if(arr[i]%k == 0){
                time += arr[i]/k;
            }
            else{
                time += (arr[i]/k)+1;
            }
        }
        if(time<=h){
            return true;
        }
        return false;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int lo=1;
        int hi=INT_MIN;
        for(int i=0;i<piles.size();i++){
            hi = max(hi,piles[i]);
        }
        int ans=-1;
        while(lo<=hi){
            int mid = (lo+hi)/2;

            if(isPossAns(piles,mid,h)){
                ans=mid;
                hi = mid-1;
            }
            else{
                lo = mid+1;
            }
        }
        return ans;
    }
};
