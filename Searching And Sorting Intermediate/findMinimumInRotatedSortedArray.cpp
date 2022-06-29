#include<bits/stdc++.h>
using namespace std;

int solution(vector<int> & arr){
       //Write your code here
       int lo=0,hi=arr.size()-1;
       if(arr[lo]<=arr[hi]){
           return arr[lo];
       }
       while(lo<=hi){
           int mid = (lo+hi)/2;

           if(arr[mid]<arr[mid-1]){
               return arr[mid];
           }

           if(arr[mid]>arr[mid+1]){
               return arr[mid+1];
           }

           if(arr[lo]<=arr[mid]){
               lo = mid+1;
           }
           else if(arr[mid]<=arr[hi]){
               hi=mid-1;
           }
       }
       return -1;
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n,0);
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    int ans = solution(arr);
    cout<<ans<<endl;
}
