#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> pairs;

class Pair{
    public:
    int x,y;
    Pair(int x,int y){
        this->x=x;
        this->y=y;
    }
};

//METHOD 1 
// int bfs(vector<vector<int>>&grid,int r,int c,vector<vector<bool>>&vis){
//     queue<Pair>q;
//     q.push(Pair(r,c));
//     int m=grid.size();
//     int n=grid[0].size();
//     // vector<vector<bool>>vis(m,vector<bool>(n,false));
//     while(!q.empty()){
//         Pair rem = q.front();
//         q.pop();

//         int x=rem.x;
//         int y=rem.y;
//         vis[x][y]=true;
//         if(grid[x][y]==1){
//             int ans = abs(x-r)+abs(y-c);
//             return ans;
//         }

//         if(x-1>=0 && vis[x-1][y]==false){
//             q.push(Pair(x-1,y));
//         }
//         if(y-1>=0 && vis[x][y-1]==false){
//             q.push(Pair(x,y-1));
//         }
//         if(x+1<m && vis[x+1][y]==false){
//             q.push(Pair(x+1,y));
//         }
//         if(y+1<n && vis[x][y+1]==false){
//             q.push(Pair(x,y+1));
//         }
//     }
//     return -1;
// }

// int maxDistance(vector<vector<int>>&grid){
//     // write code here
//     int ans=-1;
//     int m=grid.size();
//     int n=grid[0].size();
//     vector<vector<bool>>vis(m,vector<bool>(n,false));
//     for(int i=0;i<m;i++){
//         for(int j=0;j<n;j++){
//             if(grid[i][j]==0 && vis[i][j]==false){
//                 ans=max(ans,bfs(grid,i,j,vis));
//             }
//         }
//     }
//     return ans;
// }

// METHOD 2
int maxDistance(vector<vector<int>>&grid){
    // write code here
    // int ans=-1;
    int m=grid.size();
    int n=grid[0].size();
    // vector<vector<bool>>vis(m,vector<bool>(n,false));
    queue<Pair>q;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(grid[i][j]==1){
                q.push(Pair(i,j));
            }
        }
    }

    if(q.size()==0 || q.size()== m*n){
        return -1;
    }
    int max=0;
    while(!q.empty()){
        int qSize=q.size();
        for(int i=0;i<qSize;i++){
            Pair rem = q.front();
            q.pop();

            int x=rem.x;
            int y=rem.y;
            if(x-1>=0 && grid[x-1][y]==0){
                grid[x-1][y]=1;
                q.push(Pair(x-1,y));
            }
            if(y-1>=0 && grid[x][y-1]==0){
                grid[x][y-1]=1;
                q.push(Pair(x,y-1));
            }
            if(x+1<m && grid[x+1][y]==0){
                grid[x+1][y]=1;
                q.push(Pair(x+1,y));
            }
            if(y+1<n && grid[x][y+1]==0){
                grid[x][y+1]=1;
                q.push(Pair(x,y+1));
            }
        }
        max++;
    }
    return max-1;
}

int main(){
    int n;
    cin>>n;
    
    vector<vector<int>>arr(n,vector<int>(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            int x;
            cin>>x;
            arr[i][j]=x;
        }
    }
    
    cout<<maxDistance(arr);
}
