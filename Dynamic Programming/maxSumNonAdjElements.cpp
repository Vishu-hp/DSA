#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;

    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    int inc;
    int exc;
    inc=arr[0];
    exc=0;
    for(int i=1;i<n;i++){
        int ninc = arr[i] + exc;
        int nexc = max(inc,exc);

        inc = ninc;
        exc = nexc;
    }
    int ans= max(inc,exc);
    cout<<ans<<endl;
    return 0;
}
