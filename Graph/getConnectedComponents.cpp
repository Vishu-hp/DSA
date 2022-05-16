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
   
   void dfs(int src,vector<int>&dfsArr,vector<bool>&vis,vector<Edge>graph[]){
       vis[src]=true;
       dfsArr.push_back(src);
       for(auto x:graph[src]){
           if(vis[x.nbr]==false){
               dfs(x.nbr,dfsArr,vis,graph);
           }
       }
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

      
       vector<vector<int>> comps;
       
      // write your code here
      vector<bool>vis(vtces,false);
      for(int i=0;i<vtces;i++){
          if(vis[i]==false){
              vector<int>dfsArr;
              dfs(i,dfsArr,vis,graph);
              comps.push_back(dfsArr);
          }
      }
  
   
        cout<<"[";
        for(int i = 0 ; i<comps.size() ; i++){
            cout<<"[";
            for(int j = 0 ; j<comps[i].size() ; j++){
                if(j!=comps[i].size()-1)
                    cout<<comps[i][j]<<", ";
                else
                    cout<<comps[i][j];

            }
            cout<<"]";
            if(i!=comps.size()-1)cout<<", ";
        }
        cout<<"]";
    }
