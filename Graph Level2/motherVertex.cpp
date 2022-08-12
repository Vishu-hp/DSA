#include<bits/stdc++.h>
using namespace std;


void dfs(vector<vector<int>>&adjlist,int v,vector<bool>&vis,stack<int>&st){
    vis[v]=true;

    for(auto x:adjlist[v]){
        if(vis[x]==false){
            dfs(adjlist,x,vis,st);
        }
    }
    st.push(v);
}

void dfs2(vector<vector<int>>&adjlist,int v,int &cnt,vector<bool>&vis){
    vis[v]=true;
    cnt++;

    for(auto x:adjlist[v]){
        if(vis[x]==false){
            dfs2(adjlist,x,cnt,vis);
        }
    }
    
}

int findMotherVertex(int n,vector<vector<int>> &adjlist)
{
    stack<int>st;
    vector<bool>vis(n,false);
    for(int i=0;i<n;i++){
        if(vis[i]==false){
            dfs(adjlist,i,vis,st);
        }
    }
    for(int i=0;i<n;i++){
        vis[i]=false;
    }

    while(st.size()>0){
        int tmp = st.top();
        st.pop();
        int cnt=0;
        if(vis[tmp]==false){
            dfs2(adjlist,tmp,cnt,vis);
            if(cnt==n){
               return tmp+1;
            }
        }
    }
    return -1;
}

int main()
{
    int n,m;cin>>n>>m;
    vector<vector<int>> adjlist(n);
    for(int i=0;i<m;++i)
    {
        int u,v;cin>>u>>v;
        adjlist[u-1].push_back(v-1);
    }
    cout<<findMotherVertex(n,adjlist)<<"\n";
    return 0;
}
