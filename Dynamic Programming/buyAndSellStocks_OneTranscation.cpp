#include <iostream>
#include <vector>

using namespace std;

  void Transaction(vector<int> &arr){
    //write your code here
    int maxProfit = 0;
    int minSoFar = arr[0];
    for(int i=1;i<arr.size();i++){
      if(minSoFar > arr[i]){
        minSoFar = arr[i];
      }

      int cp = arr[i] - minSoFar;
      if(cp>maxProfit){
        maxProfit = cp;
      }
    }
    cout<<maxProfit<<endl;
    return;
  }
    
  int  main() {
      int n;
    cin>>n;
    vector<int>arr(n, 0);
    for (int i = 0; i < arr.size(); i++) {
      cin >> arr[i];
    }
   Transaction(arr);
     return 0;  
  }
