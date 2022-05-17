#include<bits/stdc++.h>
using namespace std;

//function to display the 2-d array
void display(vector<vector<int>> &chess){
    for(int i=0;i<chess.size();i++){
        for(int j=0;j<chess.size();j++){
            cout << chess[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

bool check(vector<vector<int>>&chess){
    for(int i=0;i<chess.size();i++){
        for(int j=0;j<chess.size();j++){
            if(chess[i][j]==-1){
                return false;
            }
        }
    }
    return true;
}

void printKnightsTour(vector<vector<int>> &chess,int n,int r,int c,int cnt){
  //write your code here
  
  if(r<0 || c<0 || r>=n || c>=n || chess[r][c]!=-1 || cnt> n*n){
      return;
  }

    if(cnt== n*n){
      chess[r][c]=cnt;
          for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
              cout<<chess[i][j]<<" ";
          }
          cout<<endl;
      }
      cout<<endl;
    
    chess[r][c]=-1;
      return;
  }

    chess[r][c]=cnt;
    printKnightsTour(chess,n,r-2,c+1,cnt+1);
    printKnightsTour(chess,n,r-1,c+2,cnt+1);
    printKnightsTour(chess,n,r+1,c+2,cnt+1);
    printKnightsTour(chess,n,r+2,c+1,cnt+1);
    printKnightsTour(chess,n,r+2,c-1,cnt+1);
    printKnightsTour(chess,n,r+1,c-2,cnt+1);
    printKnightsTour(chess,n,r-1,c-2,cnt+1);
    printKnightsTour(chess,n,r-2,c-1,cnt+1);
    chess[r][c]=-1;
    }
    
int main(){
    int n;
    cin>>n;
    int srcR,srcC;
    cin>>srcR>>srcC;
    vector<vector<int>>chess(n,vector<int>(n,-1));
    printKnightsTour(chess,n,srcR,srcC,1);    
}
