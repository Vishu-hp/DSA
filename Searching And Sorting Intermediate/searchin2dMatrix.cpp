#include<bits/stdc++.h>
using namespace std;
    
int binary_search1(vector<vector<int>>&matrix,int target){
    int lo=0,hi=matrix.size()-1;
    while(lo<=hi){
        int mid = (lo+hi)/2;

        if(matrix[mid][0]<=target && matrix[mid][matrix[0].size()-1]>=target){
            return mid;
        }

        if(matrix[mid][0]>target){
            hi = mid-1;
        }
        else if(matrix[mid][0]<target){
            lo=mid+1;
        }
    }
    return -1;
}

bool binary_search2(vector<vector<int>>&matrix,int ansRow,int target){
    int lo=0,hi = matrix[ansRow].size()-1;
    while(lo<=hi){
        int mid = (lo+hi)/2;

        if(matrix[ansRow][mid]==target){
            return true;
        }

        if(matrix[ansRow][mid]>target){
            hi = mid-1;
        }
        else{
            lo = mid+1;
        }
    }
    return false;
}

bool search(vector<vector<int>> &matrix,int target) {
    //write your code here
    int m = matrix.size();
    int n = matrix[0].size();

    int ansRow = binary_search1(matrix,target);
    if(ansRow!=-1){
        bool ans = binary_search2(matrix,ansRow,target);
        return ans;
    }
    return false;
}

int main()
{
    int m;
    cin>>m;
    int n;
    cin>>n;
    
    vector<vector<int>> matrix(m,vector<int>(n));
    
    for(int i=0; i < m;i++) {
            for(int j=0; j < n;j++) {
                cin>>matrix[i][j];
            }
        }
        
        int target;
        cin>>target;
        
        bool isFound = search(matrix,target);
    
        if(isFound == 0)
        cout<<"false";
        else if(isFound == 1)
        cout<<"true";
}
