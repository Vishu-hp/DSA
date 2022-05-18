#include <iostream>
#include <vector>
#include <queue>
#include<string>
using namespace std;

class Edge
{
public:
  int src = 0;
  int nbr = 0;
  int wt;

  Edge(int src, int nbr,int wt)
  {
    this->src = src; 
    this->nbr = nbr;
    this->wt = wt;
  }
};
  
class Pair{
  public:
  int v;
  string psf;

  Pair(int v,string psf){
    this->v=v;
    this->psf=psf;
  }
};

 bool bfs(vector<Edge>graph[],int s,vector<bool>&vis){
  queue<Pair>q;
  string tmp = to_string(s);
  q.push(Pair(s,tmp));
  while(!q.empty()){
    Pair rem = q.front();
    q.pop();
    if(vis[rem.v]==true){
      return true;
    }
    vis[rem.v]=true;
    for(auto x:graph[rem.v]){
      if(vis[x.nbr]==false){
        q.push(Pair(x.nbr,rem.psf + to_string(x.nbr)));
      }
    }
  }
  return false;
}

int main() {                                                                        
  int vtces;
  cin >> vtces;
  vector<Edge> graph[vtces];
  

  int edges;
  cin >> edges;

  for (int i = 0; i < edges; i++ ) {
    int u, v, w; 
    cin >> u >> v >> w;
 
    graph[u].push_back(Edge(u, v,w));
    graph[v].push_back(Edge(v, u,w));

  } 
 
 // write your code here 
 vector<bool>vis(vtces,false);
 bool ans=false;
 for(int i=0;i<vtces;i++){
   if(vis[i]==false){
     ans = bfs(graph,i,vis);
     if(ans){
       cout<<"true"<<endl;
       break;
     }
   }
 }
  if(ans==false){
    cout<<"false"<<endl;
  }
  return 0;
}
