#include<bits/stdc++.h>
using namespace std;

void swap(string &str,int i,int j){
    char tmp=str[i];
    str[i]=str[j];
    str[j]=tmp;

    return;
}

int slidingPuzzle(vector<vector<int>>&v1)
{
    string str="";
    for(int i=0;i<v1.size();i++){
        for(int j=0;j<v1[0].size();j++){
            str += to_string(v1[i][j]);
        }
    }
    string ans="123450";
    
    queue<string>q;
    q.push(str);
    unordered_map<string,bool>vis;
    vector<vector<int>>dirs= {{1,3},{0,2,4},{1,5},{0,4},{1,3,5},{2,4}};
    int level=0;
    while(q.size()>0){
        int n=q.size();
        for(int i=0;i<n;i++){
            string rem = q.front();
            q.pop();
            
            
            if(vis[rem]==true){
                continue;
            }
            vis[rem]=true;
            if(rem == ans){
                return level;
            }

            int idx;
            for(int i=0;i<rem.length();i++){
                if(rem[i]=='0'){
                    idx=i;
                    break;
                }
            }
            vector<int>dir = dirs[idx];
            for(int i=0;i<dir.size();i++){
                string tmp=rem;
                swap(tmp,idx,dir[i]);
                if(vis.find(tmp) == vis.end()){
                    q.push(tmp);
                }
            }

        }
        level++;
    }
    return -1;
}

int main()
{
    vector<vector<int>> v1(2,vector<int>(3));
    for(int i=0;i<2;++i) 
        for(int j=0;j<3;++j) cin>>v1[i][j];
    int ans=slidingPuzzle(v1);
    cout<<ans<<"\n";
    return 0;
}
