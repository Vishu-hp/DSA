#include <iostream>
#include <vector>

using namespace std ;

    int main() {
        int n ;
        cin>>n ;
        int m ;
        cin>>m ;
    //   write your code here
        vector<int>ans(n+1);
        
        ans[0]=0;
        for(int l=1;l<n+1;l++){
            if(l<m){
                ans[l]=1;
            }
            else if(l==m){
                ans[l]=2;
            }
            else{
                ans[l] = ans[l-1]+ans[l-m];
            }
        }
        cout<<ans[n]<<endl;
         
        return 0;
    }
