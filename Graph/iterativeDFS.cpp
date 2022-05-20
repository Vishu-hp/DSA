#include <iostream>
#include <vector>
#include <stack>
#include<string>
using namespace std;

class Edge
{
public:
  int src;
  int nbr;
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
    this->v = v;
    this->psf = psf;
  }
 };

int main() {                                                                        
  int vtces;
  cin >> vtces;
  vector<Edge>graph[vtces];
  

  int edges;
  cin >> edges;

  for (int i = 0; i < edges; i++ ) {
    int u, v, w; 
    cin >> u >> v >> w;
    graph[u].push_back(Edge(u, v,w));
    graph[v].push_back(Edge(v, u,w));
   } 
  
  int src; 
  cin >> src;
  // write your code here     
  stack<Pair>s;
  vector<bool>vis(vtces,false);
  string path =to_string(src);
  Pair tmp = Pair(src,path);
  s.push(tmp);
  while(!s.empty()){
    Pair rem = s.top();
    s.pop();
    if(vis[rem.v]==true){
      continue;
    }
    vis[rem.v]=true;
    cout<<rem.v<<"@"<<rem.psf<<endl;
    for(auto x:graph[rem.v]){
      if(vis[x.nbr]==false){
        s.push(Pair(x.nbr,rem.psf + to_string(x.nbr)));
      }
    }
  }
  return 0;
}
