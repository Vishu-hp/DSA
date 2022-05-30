#include <iostream>
#include <vector>

using namespace std ;

    int main() {
       int n ;
       cin>>n ;
     // write your code here
        vector<int>ways(n+1);
        ways[0]=0;
        ways[1]=1;
        ways[2]=2;
        for(int i=3;i<n+1;i++){
            ways[i] = ways[i-1] + (i-1)*ways[i-2];
        }
        cout<<ways[n]<<endl;
        return 0;
   }
