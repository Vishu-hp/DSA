#include<bits/stdc++.h>
using namespace std;

void findOrder(int numCourses,vector<vector<int>>& graph){
		vector<int>ans(numCourses);
		vector<int>inDegree(numCourses);

		for(int i=0;i<numCourses;i++){
			for(auto x:graph[i]){
				inDegree[x]++;
			}
		}
		queue<int>q;
		int idx=0;
		for(int i=0;i<numCourses;i++){
			if(inDegree[i]==0){
				q.push(i);
			}
		}

		while(q.size()>0){
			int rem = q.front();
			q.pop();
			ans[idx]=rem;
			idx++;
			for(auto x:graph[rem]){
				inDegree[x]--;
				if(inDegree[x]==0){
					q.push(x);
				}
			}
		}

		if(idx==numCourses){
			for(int i=0;i<numCourses;i++){
				cout<<ans[i]<<" ";
			}
		}
		else{
			cout<<"-1";
		}
		cout<<endl;
		return;
}

int main(){

	int n,m;
	cin>>n>>m;


	vector<vector<int>> graph(n);

	for(int i=0;i<m;i++){
		int u,v;
		cin>>u>>v;
		graph[v].push_back(u);
	}

	// vector<int>ans(n);
	findOrder(n,graph);
}
