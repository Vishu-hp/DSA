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
   
   void printAllPaths(vector<Edge>graph[],int src,int des,string tmp,vector<bool>&vis){
      if(src==des){
         tmp += to_string(des);
         cout<<tmp<<endl;
         return;
      }
      vis[src]=true;
      for(auto x:graph[src]){
         if(vis[x.nbr]==false){
            printAllPaths(graph,x.nbr,des,tmp+to_string(x.src),vis);
         }
      }
      vis[src]=false;
      return;
   }

   int main(){
      int vtces;
      cin>>vtces;
      vector<Edge>graph[vtces];

      int edges;
      cin>>edges;
      for(int i = 0; i < edges; i++){
         int v1 ;
         int v2 ;
         int wt ;
         cin>>v1>>v2>>wt;
         graph[v1].push_back( Edge(v1, v2, wt));
         graph[v2].push_back( Edge(v2, v1, wt));
      }

      int src;
      cin>>src;
      int dest;
      cin>>dest;
      // write your code here
      vector<bool>vis(vtces,false);
      string str="";
      printAllPaths(graph,src,dest,str,vis);
    }
