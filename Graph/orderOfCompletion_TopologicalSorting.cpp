#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Edge
{  
public:
  int src = 0; 
  int nbr = 0;

  Edge(int src, int nbr)
  {
    this->src = src; 
    this->nbr = nbr;

  }
};

void topologicalSort(vector<vector<Edge>>&graph,int s,vector<bool>&vis,stack<int>&st){
  vis[s]=true;
  for(auto x:graph[s]){
    if(vis[x.nbr]==false){
      topologicalSort(graph,x.nbr,vis,st);
    }
  }
  st.push(s);
  return;
}

int main() {                                                                             
  
  int vtces;
  cin >> vtces;
  vector<vector<Edge>> graph(vtces, vector<Edge>());
  
  
  int edges;
  cin >> edges;

  for (int i = 0; i < edges; i++ ) {  
    int u, v;  
    cin >> u >> v;   
 
    graph[u].push_back(Edge(u, v)); 
  } 

  //write your code here  
  vector<bool>vis(vtces,false);
  stack<int>st;
  for(int i=0;i<vtces;i++){
    if(vis[i]==false){
      topologicalSort(graph,i,vis,st);
    }
  }

  while(!st.empty()){
    int rem = st.top();
    cout<<rem<<endl;
    st.pop();
  }
  return 0;
}
