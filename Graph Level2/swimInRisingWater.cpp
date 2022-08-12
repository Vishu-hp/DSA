#include<bits/stdc++.h>
using namespace std;

class Pair{
    public:
    int x;
    int y;
    int h;
    
    Pair(int x,int y,int h){
        this->x=x;
        this->y=y;
        this->h=h;
    }
};

bool operator <(const Pair &p1,const Pair &p2){
    return p1.h>p2.h;
}

int swimInRisingWater(vector<vector<int>>&grid)
{
    int m = grid.size() , n = grid[0].size();
        vector<vector<bool>>vis(m,vector<bool>(n,false));
        priority_queue<Pair>pq;
        pq.push(Pair(0,0,grid[0][0]));
        int dx[4] = {-1,0 ,+1,0};
        int dy[4] = {0 ,+1 ,0, -1};
        while(pq.size()>0){
            Pair rem = pq.top();
            pq.pop();
            
            if(vis[rem.x][rem.y]==true){
                continue;
            }
            vis[rem.x][rem.y]=true;
            
            if(rem.x == m-1 && rem.y==n-1){
                return rem.h;
            }
            
            for(int i=0;i<4;i++){
                int nx = rem.x + dx[i];
                int ny = rem.y + dy[i];
                
                if(nx<0 || ny<0 || nx>=m || ny>=n || vis[nx][ny]==true){
                    continue;
                }
                
                pq.push(Pair(nx,ny,max(rem.h,grid[nx][ny])));
            }
        }
        return -1;
}

int main()
{
    int n;cin>>n;
    int m;cin>>m;
    vector<vector<int>> grid(n,vector<int>(m));
    for(int i=0;i<n;++i)
        for(int j=0;j<m;++j) cin>>grid[i][j];
    cout<<swimInRisingWater(grid)<<"\n";
    return 0;
}
