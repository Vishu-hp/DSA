#include<bits/stdc++.h>
using namespace std;

class Pair{
    public:
    int v;
    int wt;

    Pair(int v,int wt){
        this->v=v;
        this->wt=wt;
    }
};

class Edge{
    public:
    int s;
    int n;
    int w;

    Edge(int s,int n,int w){
        this->s=s;
        this->n=n;
        this->w=w;
    }
};

void makeGraph(vector<Edge>*graph,vector<vector<int>>& pipes,vector<int>&wells){
    for(int i=0;i<pipes.size();i++){
        int s = pipes[i][0];
        int n = pipes[i][1];
        int w = pipes[i][2];
        graph[s].push_back(Edge(s,n,w));
        graph[n].push_back(Edge(n,s,w));
    }
    for(int i=0;i<wells.size();i++){
        graph[0].push_back(Edge(0,i+1,wells[i]));
    }
    return;
}

bool operator<(const Pair &a,const Pair &b){
    if(a.wt!=b.wt){
        return a.wt>b.wt;
    }

}

int minCostToSupplyWater(int n, vector<int>&wells, vector<vector<int>>& pipes){
//write your code here
    vector<Edge>graph[n+1];
    makeGraph(graph,pipes,wells);

    priority_queue<Pair>pq;
    int ans = 0;
    pq.push(Pair(0,0));
    vector<bool>vis(n+1,false);
    while(pq.size()>0){
        Pair rem = pq.top();
        pq.pop();

        if(vis[rem.v]==true){
            continue;
        }
        vis[rem.v]=true;
        ans += rem.wt;
        for(auto x:graph[rem.v]){
            if(vis[x.n]==false){
                pq.push(Pair(x.n,x.w));
            }
        }
    }
    return ans;
}


int main(){
    int v,e;
    cin>>v>>e;
    
    
    vector<int>wells(v);
    
    for(int i=0;i<v;i++){
        cin>>wells[i];
    }
    
    
    vector<vector<int>>pipes(e,vector<int>(3));
    
    for(int i=0;i<e;i++){
        for(int j=0;j<3;j++){
            cin>>pipes[i][j];
        }
    }
    
    cout<<minCostToSupplyWater(v, wells, pipes);
    
}
