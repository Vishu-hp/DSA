#include<bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin>>n;

    int zero = 1;
    int one = 1;

    for(int i=2;i<n+1;i++){
        int nzero = one;
        int none = zero + one;

        zero = nzero;
        one =none;
    }

    cout<<zero+one<<endl;
    return 0;
}
