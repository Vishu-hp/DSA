#include<bits/stdc++.h>
using namespace std;

int isNegativeWeightCycle(int n,vector<vector<int>>&edges)
{
     vector<int>path(n,INT_MAX);
     path[0]=0;

     for(int i=1;i<n;i++){
         for(int i=0;i<edges.size();i++){
             if(path[edges[i][0]]==INT_MAX){
                 continue;
             }
             if(path[edges[i][0]]+edges[i][2] < path[edges[i][1]]){
                 path[edges[i][1]] = path[edges[i][0]]+ edges[i][2];
             }
         }
     }

     for(int i=0;i<edges.size();i++){
          if(path[edges[i][0]]==INT_MAX){
                 continue;
             }
         if(path[edges[i][0]]+edges[i][2] < path[edges[i][1]]){
             return 1;
         }
     }
     return 0;
}

int main(){
    
    int n,m;
    cin>>n>>m;

    vector<vector<int>> edges(m,vector<int>(3));
    
    for(int i=0;i<m;i++){
        int x,y,z;
        cin>>x>>y>>z;
        
        edges[i][0]=x;
        edges[i][1]=y;
        edges[i][2]=z;
        
    }
    
    cout<<isNegativeWeightCycle(n, edges)<<endl;
}
