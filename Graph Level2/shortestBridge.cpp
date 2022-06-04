#include<bits/stdc++.h>
using namespace std;

class Pair{
    public:
    int x,y;

    Pair(int x,int y){
        this->x=x;
        this->y=y;
    }
};

// int bfs(vector<vector<int>>&v1,int r,int c){
//     queue<Pair>q;
//     int level=0;
//     vector<vector<bool>>vis(v1.size(),vector<bool>(v1.size(),false));
//     q.push(Pair(r,c));
//     while(!q.empty()){
//         int n=q.size();
//         for(int i=0;i<n;i++){
//             Pair rem = q.front();
//             q.pop();

//             int x=rem.x;
//             int y=rem.y;

//             if(x!=r && y!=c && v1[x][y]==1){
//                 return level;
//             }

//             if(vis[x][y]==true){
//                 continue;
//             }
//             vis[x][y]=true;
//             if(x-1>=0 && vis[x-1][y]==false){
//                 q.push(Pair(x-1,y));
//             }
//             if(y-1>=0 && vis[x][y-1]==false){
//                 q.push(Pair(x,y-1));
//             }
//             if(x+1<v1.size() && vis[x+1][y]==false){
//                 q.push(Pair(x+1,y));
//             }
//             if(y+1<v1.size() && vis[x][y+1]==false){
//                 q.push(Pair(x,y+1));
//             }
//         }
//         level++;
//     }
//     return -1;
// }

void dfs(vector<vector<int>>&v1,int r,int c,queue<Pair>&q,vector<vector<bool>>&vis){
    vis[r][c]=true;
    q.push(Pair(r,c));

    if(r-1>=0 && v1[r-1][c]==1 && vis[r-1][c]==false){
        dfs(v1,r-1,c,q,vis);
    }
    if(c-1>=0 && v1[r][c-1]==1 && vis[r][c-1]==false){
        dfs(v1,r,c-1,q,vis);
    }
    if(r+1<v1.size() && v1[r+1][c]==1 && vis[r+1][c]==false){
        dfs(v1,r+1,c,q,vis);
    }
    if(c+1<v1[0].size() && v1[r][c+1]==1 && vis[r][c+1]==false){
        dfs(v1,r,c+1,q,vis);
    }
}

int shortestBridge(vector<vector<int>>&v1)
{
    queue<Pair>q;
    int m=v1.size();
    int n=v1[0].size();
    vector<vector<bool>>vis(m,vector<bool>(n,false));
    bool flag=false;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(v1[i][j]==1){
                flag=true;
                dfs(v1,i,j,q,vis);
                break;
            }
        }
        if(flag){
            break;
        }
    }

    int level=0;
    while(!q.empty()){
        int n=q.size();
        for(int i=0;i<n;i++){
            Pair rem=q.front();
            q.pop();
            int x=rem.x;
            int y=rem.y;

            if(x-1>=0 && vis[x-1][y]==false){
                if(v1[x-1][y]==1){
                    return level;
                }
                vis[x-1][y]=true;
                q.push(Pair(x-1,y));
            }
            if(y-1>=0 && vis[x][y-1]==false){
                if(v1[x][y-1]==1){
                    return level;
                }
                vis[x][y-1]=true;
                q.push(Pair(x,y-1));
            }
            if(x+1<v1.size() && vis[x+1][y]==false){
                if(v1[x+1][y]==1){
                    return level;
                }
                vis[x+1][y]=true;
                q.push(Pair(x+1,y));
            }
            if(y+1<v1.size() && vis[x][y+1]==false){
                if(v1[x][y+1]==1){
                    return level;
                }
                vis[x][y+1]=true;
                q.push(Pair(x,y+1));
            }
        }
        level++;
    }
    return -1;
}

int main()
{
    int n;cin>>n;
    vector<vector<int>> v1(n,vector<int>(n));
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<n;++j) cin>>v1[i][j];
    }
    cout<<shortestBridge(v1);
    return 0;
}
