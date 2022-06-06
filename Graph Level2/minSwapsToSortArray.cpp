#include<bits/stdc++.h>
using namespace std;

class Pair{
    public:
    int v;
    int i;
};

bool compare(Pair &a,Pair &b){
    if(a.v != b.v){
        return a.v<b.v;
    }
    else{
        return a.i <b.i;
    }
}

int minSwaps(vector<int> &arr1)
{

    //write code here
    int n=arr1.size();
    vector<Pair>help(n);
    for(int i=0;i<n;i++){
        help[i].v=arr1[i];
        help[i].i = i;
    }
    sort(help.begin(),help.end(),compare);
    int ans=0;
    vector<bool>vis(n,false);
    for(int i=0;i<n;i++){
        if(vis[i]==true || help[i].i == i){
            continue;
        }

        int j=i;
        int clen=0;
        while(vis[j]==false){
            vis[j]=true;
            clen++;
            j = help[j].i;
        }
        ans += (clen-1);
    }   
    return ans;
}

int main()
{
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    
    cout<<minSwaps(arr);
}
