#include <iostream>
#include <vector>

using namespace std;

  void transactions(vector<int> &arr){

 // write your code here
  int ans = 0;
  int peak=0;
  int valley=0;

  for(int i=1;i<arr.size();i++){
    if(arr[i]<arr[i-1]){
      ans += arr[peak]-arr[valley];
      peak=i;
      valley=i;
    }
    else{
      peak=i;
    }
  }

  ans += arr[peak]-arr[valley];
  cout<<ans<<endl;
  return;
}
  
  int main() {
    int n ;
    cin>>n;
    vector<int> arr(n,0);
    for (int i = 0; i < arr.size(); i++) {
      cin>> arr[i];
    }
    
    transactions(arr);
    return 0;
  }
