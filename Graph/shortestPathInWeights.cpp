#include <bits/stdc++.h>

using namespace std;

class Edge
{  
public:
  int src = 0; 
  int nbr = 0;
  int wt = 0;

  Edge(int src, int nbr, int wt)
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
    int w;

    Pair(int v,string psf,int w){
      this->v=v;
      this->psf=psf;
      this->w = w;
    }
} ;

bool operator <(const Pair &p1,const Pair &p2){
  if(p1.w!= p2.w){
    return p1.w>p2.w;
  }
  else if(p1.v != p2.v){
    return p1.v>p2.v;
  }
  else {
    return p1.psf.length()<p2.psf.length();
  }
}

void dijkstra(vector<vector<Edge>>&graph,int s,vector<bool>&vis){
  priority_queue<Pair>pq;
  string tmp = to_string(s);
  pq.push(Pair(s,tmp,0));
  while(!pq.empty()){
    Pair rem = pq.top();
    pq.pop();

    if(vis[rem.v]==true){
      continue;
    }

    vis[rem.v]=true;
    cout<<rem.v<<" via "<<rem.psf<<" @ "<<rem.w<<endl;
    for(auto x:graph[rem.v]){
      if(vis[x.nbr]==false){
        pq.push(Pair(x.nbr,rem.psf+to_string(x.nbr),rem.w+x.wt));
      }
    }
  }
  return;
} 

int main() {                                                                            
 
  int vtces;
  cin >> vtces;
  vector<vector<Edge>> graph(vtces, vector<Edge>());
  

  int edges;
  cin >> edges;

  for (int i = 0; i < edges; i++ ) {
    int u, v, w; 
    cin >> u >> v >> w; 
 
    graph[u].push_back(Edge(u, v, w));
    graph[v].push_back(Edge(v, u, w));

  } 
  int src;  
  cin >> src;  
    
  //write your code here
  vector<bool>vis(vtces,false);  
  dijkstra(graph,src,vis);
  return 0;
}
