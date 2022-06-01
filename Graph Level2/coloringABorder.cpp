#include<bits/stdc++.h>
using namespace std;

void coloring_border(vector<vector<int>>& arr, int row, int col, int color) {
    arr[row][col]=-color;
    int count=0;

    if(row-1>=0){
      if(arr[row-1][col]<0){
        count++;
      }
      if(arr[row-1][col] == color){
        count++;
        coloring_border(arr,row-1,col,color);
      }
    }
    if(col-1>=0){
      if(arr[row][col-1] <0){
          count++;
      }
      if(arr[row][col-1] == color){
          count++;
          coloring_border(arr,row,col-1,color);
      }
    }
    if(col+1< arr[0].size()){
      if(arr[row][col+1] <0){
            count++;
        }
        if(arr[row][col+1] == color){
            count++;
            coloring_border(arr,row,col+1,color);
        }
    }
    if(row+1< arr.size()){
      if(arr[row+1][col] < 0){
        count++;
      }
      if(arr[row+1][col] == color){
        count++;
        coloring_border(arr,row+1,col,color);
      }
    }

    if(count==4){
        arr[row][col] = color;
    }
    return;
}

int main() {

  int n, m;
  cin >> m >> n;

  vector<vector<int>>arr(m, vector<int>(n));

  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      cin >> arr[i][j];
    }
  }

  int row, col, color;
  cin >> row >> col >> color;

  coloring_border(arr, row, col, arr[row][col]);

  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      if(arr[i][j]<0){
        cout << color << "\t";
      }
      else{
        cout<<arr[i][j]<<"\t";
      }
    }
    cout<<endl;
    // cout << arr[i][j] << "\t";
  }

  return 0;
}
