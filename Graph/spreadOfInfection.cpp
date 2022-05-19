#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Edge
{
public:
  int src = 0;
  int nbr = 0;
  int wt = 0;

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
  int t;
  Pair(int v,int t){
    this->v = v;
    this->t = t;
  }
};

int bfs(vector<Edge>graph[],int s,int t,vector<bool>&vis){
  queue<Pair>q;
  q.push(Pair(s,1));
  int cnt=0;
  while(!q.empty()){
    Pair rem = q.front();
    q.pop();

    if(vis[rem.v]==true){
      continue;
    }
    vis[rem.v]=true;

    if(rem.t > t){
      return cnt;
    }
    cnt++;
    for(auto x:graph[rem.v]){
      if(vis[x.nbr]==false){
        q.push(Pair(x.nbr,rem.t+1));
      }
    }
  }
  return cnt;
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
  int src,t; 
  cin >> src;
  cin >> t; 
    
  //write your code here  
  vector<bool>vis(vtces,false);
  int ans = bfs(graph,src,t,vis);
  cout<<ans<<endl;
  return 0;
}
