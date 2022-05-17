#include<bits/stdc++.h>

using namespace std;
  
class Edge{
  public:
  int src;
  int nbr;

  Edge(int src,int nbr){
    this->src=src;
    this->nbr=nbr;
  }
};

void dfs(vector<Edge>graph[],int s,vector<bool>&vis,vector<int>&dfsArr){
  vis[s]=true;
  dfsArr.push_back(s);
  for(auto x:graph[s]){
    if(vis[x.nbr]==false){
      dfs(graph,x.nbr,vis,dfsArr);
    }
  }
}

int main(){
   int n;
   cin>>n;
      
   int k;
   cin>>k;
      
   // write your code here
    int vtces=n;
    vector<Edge>graph[vtces];
    for(int i=0;i<k;i++){
      int src,des;
      cin>>src>>des;
      graph[src].push_back(Edge(src,des));
      graph[des].push_back(Edge(des,src));
    }    

    vector<vector<int>>comps;
    vector<bool>vis(vtces,false);
    for(int i=0;i<vtces;i++){
      if(vis[i]==false){
        vector<int>dfsArr;
        dfs(graph,i,vis,dfsArr);
        comps.push_back(dfsArr);
      }
    }
    int ans=0;
    for(int i=0;i<comps.size()-1;i++){
      for(int j=i+1;j<comps.size();j++){
        ans += (comps[i].size())*(comps[j].size());
      }
    }
    cout<<ans<<endl;
   return 0;
 }
