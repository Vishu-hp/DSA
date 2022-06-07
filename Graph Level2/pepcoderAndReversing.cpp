#include<bits/stdc++.h>
using namespace std;

class Edge{
    public:
    int src;
    int nbr;
    int wt;

    Edge(int src,int nbr,int wt){
        this->src=src;
        this->nbr=nbr;
        this->wt=wt;
    }
};

class Pair{
    public:
    int v;
    int w;

    Pair(int v,int w){
        this->v=v;
        this->w=w;
    }
};


// METHOD - 1
bool operator <(const Pair &p1,const Pair &p2){
  if(p1.w!= p2.w){
    return p1.w>p2.w;
  }
  else{
    return p1.v>p2.v;
  }
}


int dijkstra(vector<Edge>*graph,int s,int d){
    priority_queue<Pair>pq;
    pq.push(Pair(s,0));
    vector<bool>vis(d+1,false);
    while(pq.size()>0){
        Pair rem = pq.top();
        pq.pop();

        if(vis[rem.v]==true){
            continue;
        }
        vis[rem.v]=true;

        if(rem.v == d){
            return rem.w;
        }

        for(auto x:graph[rem.v]){
            if(vis[x.nbr]==false){
                pq.push(Pair(x.nbr,rem.w+x.wt));
            }
        }
    }
    return -1;
}

int main(){
    int n,m;
    cin>>n>>m;
    vector<Edge>graph[n+1];
    for(int i=0;i<m;i++){
        int s,d;
        cin>>s>>d;
        graph[s].push_back(Edge(s,d,0));
        graph[d].push_back(Edge(d,s,1));
    }

    cout<<dijkstra(graph,1,n)<<endl;
}
