#include<bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>>&graph,int v,vector<bool>&vis,stack<int>&st){
	vis[v] = true;
	for(auto x:graph[v]){
		if(vis[x]==false){
			dfs(graph,x,vis,st);
		}
	}
	st.push(v);
}

void dfs2(vector<vector<int>>&graph,int v,vector<bool>&vis){
	vis[v] = true;
	for(auto x:graph[v]){
		if(vis[x]==false){
			dfs2(graph,x,vis);
		}
	}
}

int kosaraju(vector<vector<int>> & graph,int N){
	stack<int>st;
	vector<bool>vis(N,false);
	for(int i=0;i<N;i++){
		if(vis[i]==false){
			dfs(graph,i,vis,st);
		}
	}

	vector<vector<int>>g2(graph.size());
	for(int i=0;i<N;i++){
		for(int x:graph[i]){
			g2[x].push_back(i);
		}
	}

	for(int i=0;i<N;i++){
		vis[i] = false;
	}
	int ans=0;
	while(st.size()>0){
		int top = st.top();
		st.pop();

		if(vis[top]==false){
			dfs2(g2,top,vis);
			ans++;
		}
	}
	return ans;
}

int main(){
    int n, m;
    cin>>n>>m;
    vector<vector<int>>graph(n); 
	for(int i = 0;i<m;i++) {
	    int u, v;
	    cin >> u >> v; 
	    graph[u-1].push_back(v-1);
	}
    cout<<kosaraju(graph, n)<<endl;
}
