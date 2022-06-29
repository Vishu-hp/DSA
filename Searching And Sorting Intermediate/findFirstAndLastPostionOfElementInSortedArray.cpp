#include<bits/stdc++.h>
using namespace std;

int binarySearchFirstIdx(vector<int>&arr,int target){
  int lo=0,hi = arr.size()-1;
  int ans=-1;
  while(lo<=hi){
    int mid = (lo+hi)/2;

    if(arr[mid]==target){
      ans = mid;
      hi=mid-1;
    }

    if(arr[mid]<target){
      lo=mid+1;
    }
    else if(arr[mid]>target){
      hi=mid-1;
    }
  }
  return ans;
}

int binarySearchLastIdx(vector<int>&arr,int target){
  int lo=0,hi = arr.size()-1;
  int ans=-1;
  while(lo<=hi){
    int mid = (lo+hi)/2;

    if(arr[mid]==target){
      ans = mid;
      lo = mid+1;
    }

    if(arr[mid]<target){
      lo=mid+1;
    }
    else if(arr[mid]>target){
      hi=mid-1;
    }
  }
  return ans;
}

void solution(vector<int>& arr, int target, vector<int>& ans){
  //Write your code here    
    int firstIdx = binarySearchFirstIdx(arr,target);
    int lastIdx = binarySearchLastIdx(arr,target);
    ans[0] = firstIdx;
    ans[1] = lastIdx;

    return;
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
    vector<int> ans(2, -1);
    solution(arr, tar, ans);
    cout<<ans[0]<<" "<<ans[1];
}
