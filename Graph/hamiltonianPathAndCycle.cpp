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


bool isPath(vector<Edge>graph[],int src,int s){
    for(auto x:graph[src]){
        if(x.nbr == s){
            return false;
        }
    }
    return true;
}

void solve(vector<Edge>graph[],int vtces,int src,int s,string tmp,unordered_set<int>&ust){
    if(ust.size()==vtces-1){
        if(isPath(graph,src,s)){
            tmp += ".";
        }
        else{
            tmp += "*";
        }
        cout<<tmp<<endl;
        return;
    }

    ust.insert(s);
    for(auto x:graph[s]){
        if(ust.find(x.nbr) == ust.end()){
            solve(graph,vtces,src,x.nbr,tmp+to_string(x.nbr),ust);
        }
    }
    ust.erase(s);
} 

int main(){
    int vtces,edges;
    cin>>vtces>>edges;
    vector<Edge>graph[vtces];
    for(int i=0;i<edges;i++){
        int src,nbr,wt;
        cin>>src>>nbr>>wt;
        graph[src].push_back(Edge(src,nbr,wt));
        graph[nbr].push_back(Edge(nbr,src,wt));
    }
    int src;
    cin>>src;
    string tmp="";
    tmp += to_string(src);
    unordered_set<int>ust;
    solve(graph,vtces,src,src,tmp,ust);
    return 0;
}
