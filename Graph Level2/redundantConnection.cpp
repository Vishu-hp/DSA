#include<bits/stdc++.h>
using namespace std;
# define N 10002
int parent[N];

void make(int v){
  parent[v]=v;
}

int find(int v){
  if(parent[v]==v){
    return v;
  }
  return parent[v]=find(parent[v]);
}

  vector<int> findRedundantConnection(vector<vector<int>>& edges) {
      for(int i=1;i<=edges.size();i++){
          make(i);
      }
      for(int i=0;i<edges.size();i++){
        int s = edges[i][0];
        int n= edges[i][1];
        if(find(s)==find(n)){
          return edges[i];
        }
        else{
          parent[find(s)] = find(n);
        }
      }
      vector<int>ans;
      return ans;
  }

  int main(){
    int n;
    cin>>n;
    vector<vector<int>>pos(n,vector<int>(2));
    for (int i = 0; i < n; i++) {
      cin>>pos[i][0];
      cin>>pos[i][1];
    }

    vector<int>ans=findRedundantConnection(pos);
    cout<<ans[0]<<" "<<ans[1]<<endl;
    return 0;
  }
