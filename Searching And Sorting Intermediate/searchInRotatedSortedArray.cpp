#include<bits/stdc++.h>
using namespace std;

int solution(vector<int> & arr, int target){
   // Write your code here
   int lo=0,hi=arr.size()-1;
   while(lo<=hi){
       int mid = (lo+hi)/2;

       if(arr[mid]==target){
           return mid;
       }

       if(arr[lo]<=arr[mid]){
           if(target>=arr[lo] && target<arr[mid]){
               hi=mid-1;
           }
           else{
               lo=mid+1;
           }
       }
       else if(arr[mid]<=arr[hi]){
           if(target>arr[mid] && target<=arr[hi]){
               lo = mid+1;
           }
           else{
               hi=mid-1;
           }
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
    int tar;
    cin>>tar;
    int ans = solution(arr,tar);
    cout<<ans<<endl;
}
