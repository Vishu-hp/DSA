#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> pairs;

class Pair{
    public:
    int r,c,l;

    Pair(int r,int c,int l){
        this->r=r;
        this->c=c;
        this->l=l;
    }
};

int orangesRotting(vector<vector<int>>& grid){
   int m=grid.size();
   int n=grid[0].size();
   int fresh=0;
   queue<Pair>q;
   for(int i=0;i<m;i++){
       for(int j=0;j<n;j++){
           if(grid[i][j]==2){
               q.push(Pair(i,j,0));
           }
           else if(grid[i][j]==1){
               fresh++;
           }
       }
   } 

   if(fresh==0){
       return 0;
   }
    int ans=0;
   while(!q.empty()){
       Pair rem = q.front();
       q.pop();
        ans=rem.l;

        int x=rem.r;
        int y=rem.c;
        if(x-1>=0 && grid[x-1][y]==1){
            grid[x-1][y]=2;
            fresh--;
            q.push(Pair(x-1,y,rem.l+1));
        }
        if(y-1>=0 && grid[x][y-1]==1){
            grid[x][y-1]=2;
            fresh--;
            q.push(Pair(x,y-1,rem.l+1));
        }
        if(x+1<grid.size() && grid[x+1][y]==1){
            grid[x+1][y]=2;
            fresh--;
            q.push(Pair(x+1,y,rem.l+1));
        }
        if(y+1<grid[0].size() && grid[x][y+1]==1){
            grid[x][y+1]=2;
            fresh--;
            q.push(Pair(x,y+1,rem.l+1));
        }
   }
   if(fresh==0){
       return ans;
   }
   return -1;
}

int main(){
    
    int n,m;
    cin>>n>>m;
    
    vector<vector<int>>arr(n,vector<int>(m));
    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            int x;
            cin>>x;
            arr[i][j]=x;
        }
    }
    
    cout<<orangesRotting(arr)<<endl;
}
