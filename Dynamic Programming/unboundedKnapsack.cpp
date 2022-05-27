#include <iostream>
#include <vector>

using namespace std;

void unboundedKnapsack(int n,vector<int> val, vector<int> weight,int cap){
    
// write your code here
    vector<int>ans(cap+1);
    ans[0]=0;
    for(int i=0;i<n;i++){
      for(int j=1;j<cap+1;j++){
        if(j>=weight[i]){
          ans[j] = max(ans[j],ans[j-weight[i]]+val[i]);
        }
      }
    }
    cout<<ans[cap]<<endl;
    return;
}


int main() {

  int n;
  cin>>n;
  vector<int> val(n);
  for (int i = 0; i < n; i++) {

    cin>>val[i];
  }
  vector<int> weight(n);
  for (int i = 0; i < n; i++) {
    cin>>weight[i];
  }
  int cap;
  cin>>cap;
  
  unboundedKnapsack(n,val, weight,cap);
  

}
