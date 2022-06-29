#include <iostream>
#include <vector>

using namespace std;

bool search(vector<vector<int>>& matrix, int target){
  // write your code here
    int rows = matrix.size();
    int cols = matrix[0].size();

    int r = 0,c = cols-1;
    while(r<rows && c>=0){
        int val = matrix[r][c];
        if(val==target){
            return true;
        }

        if(val>target){
            c--;
        }
        else{
            r++;
        }
    }
    return false;
}

int main(){
    int n, m, target;
    cin >> m;
    cin >> n;
    
    vector<vector<int>> matrix(m, vector<int> (n));
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            cin >> matrix[i][j];
        }
    }
    cin >> target;
    
    bool isFound = search(matrix, target);
    if(isFound == 0){
        cout << "false" << endl;
    }else{
        cout << "true" << endl;
    }

    return 0;
}
