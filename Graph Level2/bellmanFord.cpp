#include<bits/stdc++.h>
using namespace std;



void bellmanFord(vector<vector<int>>&edges,int src,vector<int>&path,int n){
    path[src]=0;

    for(int i=0;i<n-1;i++){
        for(int i=0;i<edges.size();i++){
            if(path[edges[i][0]]+edges[i][2] < path[edges[i][1]]){
                path[edges[i][1]] = path[edges[i][0]]+edges[i][2];
            }
        }
    }
    return;
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
    

    int src=1;
    vector<int>path(n+1,INT_MAX);
    bellmanFord(edges,src,path,n);
    for(int i=2;i<n+1;i++){
        cout<<path[i]<<" ";
    }
    return 0;
}                 
                        
