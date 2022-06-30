#include<bits/stdc++.h>
using namespace std;

bool isPossAns(vector<int>&wt,int days,int c){
    int d=1,cap=0;
    for(int i=0;i<wt.size();i++){
        cap += wt[i];
        if(cap>c){
            cap = wt[i];
            d++;
            if(d>days){
                return false;
            }
        }
    }
    return true;
}

int shipWithinDays(vector<int>& wt, int days){
    //Write your code here
    int lo=0,hi=0;
    for(int i=0;i<wt.size();i++){
        lo = max(lo,wt[i]);
        hi += wt[i];
    }
    int ans;
    while(lo<=hi){
        int mid = (lo+hi)/2;

        if(isPossAns(wt,days,mid)){
            ans=mid;
            hi = mid-1;
        }
        else{
            lo = mid+1;
        }
    }
    return ans;
}

int main(){
    int n;
    cin>>n;
    vector<int> wt(n,0);
    for(int i=0; i<n; i++){
        cin>>wt[i];
    }
    int days;
    cin>>days;

    int ans = shipWithinDays(wt, days);
    cout<<ans<<endl;
}
