#include<bits/stdc++.h>
using namespace std;

class Pair{
    public:
    int row;
    int col;
    int l;

    Pair(int row,int col,int l){
        this->row=row;
        this->col=col;
        this->l=l;
    }
};

// METHOD -1 
// int bfs(vector<vector<int>>&matrix,int r,int c){
//     queue<Pair>q;
//     q.push(Pair(r,c,0));
//     int m=matrix.size();
//     int n=matrix[0].size();
//     // vector<vector<bool>>vis(m,vector<bool>(n,false));
//     while(!q.empty()){
//         Pair rem = q.front();
//         q.pop();

//         if(matrix[rem.row][rem.col]==0){
//             return rem.l;
//         }
//         int x = rem.row;
//         int y=rem.col;
//         if(x-1>=0){
//             q.push(Pair(x-1,y,rem.l+1));
//         }
//         if(y-1>=0){
//             q.push(Pair(x,y-1,rem.l+1));
//         }
//         if(x+1<m){
//             q.push(Pair(x+1,y,rem.l+1));
//         }
//         if(y+1<n){
//             q.push(Pair(x,y+1,rem.l+1));
//         }
//     }
//     return -1;
// }

// vector<vector<int>> updateMatrix(vector<vector<int>>& matrix){
//     // write your code here
//     int m=matrix.size();
//     int n=matrix[0].size();
//     vector<vector<int>>ans(m,vector<int>(n));
//     for(int i=0;i<m;i++){
//         for(int j=0;j<n;j++){
//             if(matrix[i][j]==0){
//                 ans[i][j]=0;
//             }
//             else{
//                 int l = bfs(matrix,i,j);
//                 ans[i][j]=l;
//             }
//         }
//     }
//     return ans;
// }


//METHOD 2
vector<vector<int>> updateMatrix(vector<vector<int>>& matrix){
    // write your code here
    queue<Pair>q;
    int m=matrix.size();
    int n=matrix[0].size();
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(matrix[i][j]==1){
                matrix[i][j]=-1;
            }
            else{
                q.push(Pair(i,j,0));
            }
        }
    }

    while(!q.empty()){
        Pair rem = q.front();
        q.pop();

        int x=rem.row;
        int y=rem.col;
        if(x-1>=0 && matrix[x-1][y]==-1){
            matrix[x-1][y] = matrix[x][y]+1;
            q.push(Pair(x-1,y,rem.l+1));
        }
        if(y-1>=0 && matrix[x][y-1]==-1){
            matrix[x][y-1]=matrix[x][y]+1;
            q.push(Pair(x,y-1,rem.l+1));
        }
        if(x+1<matrix.size() && matrix[x+1][y]==-1){
            matrix[x+1][y] = matrix[x][y]+1;
            q.push(Pair(x+1,y,rem.l+1));
        }
        if(y+1<matrix[0].size() && matrix[x][y+1]==-1){
            matrix[x][y+1]=matrix[x][y]+1;
            q.push(Pair(x,y+1,rem.l+1));
        }
    }
    return matrix;
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
    
    vector<vector<int>>ans=updateMatrix(arr);
    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
}
