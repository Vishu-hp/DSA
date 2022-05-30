#include <iostream>
#include <vector>

using namespace std;

    int main() {
        int n ;
        cin>>n ;
        int k ;
        cin>>k ;
        
        //write your code here
        int same = k;
        int diff = k*(k-1);
        int total = same+diff;
        for(int i=3;i<=n;i++){
            same = diff;
            diff = total*(k-1);

            total = same+diff;
        }
        cout<<total<<endl;
        return 0;
}
