#include<bits/stdc++.h>
using namespace std;

  int countTriplets(vector<int> &arr) {
    //write your code here
    sort(arr.begin(),arr.end());
    int cnt=0;
    for(int i=arr.size()-1;i>=2;i--){
      int li=0,ri=i-1;
      while(li<ri){
        int sum = arr[li]+arr[ri];
        if(sum==arr[i]){
          cnt++;
          li++;
          ri--;
        }
        else if(sum<arr[i]){
          li++;
        }
        else{
          ri--;
        }
      }
    }
    return cnt;
  }

  int main() {
    //input work
    int n;
    cin>>n;
    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        int data;
        cin>>data;
      arr[i] = data;
    }

    cout<<countTriplets(arr);
  }
