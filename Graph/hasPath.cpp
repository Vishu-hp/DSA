#include<bits/stdc++.h>
using namespace std;
class Edge {
   public:
      int src;
      int nbr;
      int wt;

   Edge(int src, int nbr, int wt){
      this->src = src;
      this->nbr = nbr;
      this->wt = wt;
   }
};

bool hasPath(vector<Edge>*adjList,int src,int des,vector<bool>&vis){
   if(src==des){
      return true;
   }
   vis[src]=true;
   for(auto x:adjList[src]){
        int nbr = x.nbr;
        if(vis[nbr]==false){
            bool nbrHasPath = hasPath(adjList,nbr,des,vis);
            if(nbrHasPath){
               return true;
            }
         }
   }
   return false;
}

int main(){
   int v,e;
   cin>>v>>e;
   vector<Edge>adjList[v];
   for(int i=0;i<e;i++){
      int src,nbr,wt;
      cin>>src>>nbr>>wt;
      adjList[src].push_back(Edge(src,nbr,wt));
      adjList[nbr].push_back(Edge(nbr,src,wt));
   }

   int src,des;
   cin>>src>>des;
   vector<bool>vis(v,false);
   bool ans = hasPath(adjList,src,des,vis);
   if(ans){
      cout<<"true"<<endl;
   }
   else{
      cout<<"false"<<endl;
   }
   return 0;
}
