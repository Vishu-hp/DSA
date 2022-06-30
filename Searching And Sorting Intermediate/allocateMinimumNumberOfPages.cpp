#include<bits/stdc++.h>
using namespace std;
bool ispossible(vector<int> &arr,int m,int mid)
{
    //write your code here
  int sum=0;
  int st=1;
  for(int i=0;i<arr.size();i++){
    sum += arr[i];
    if(sum>mid){
      sum = arr[i];
      st++;
      if(st>m){
        return false;
      }
    }
  }
  return true;
}
int minimum_pages(vector<int> &arr,int m)
{
    //write your code here
    int lo=0,hi;
    for(int i=0;i<arr.size();i++){
      lo = max(lo,arr[i]);
      hi += arr[i];
    }

    int ans;
    while(lo<=hi){
      int mid = (lo+hi)/2;
      if(ispossible(arr,m,mid)){
        ans= mid;
        hi = mid-1;
      }
      else{
        lo = mid+1;
      }
    }
    return ans;
}

int main()
{
 int n;
 cin>>n;
 
 vector<int> arr(n);
 for(int i=0;i<n;i++)
 {
     cin>>arr[i];
 }
 int m;
 cin>>m;
 int x=minimum_pages(arr,m);
 cout<<x;
}
