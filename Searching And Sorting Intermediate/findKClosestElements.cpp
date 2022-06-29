#include<bits/stdc++.h>
#include<iostream>

using namespace std;

class Pair{
    public:
    int val;
    int gap;

    Pair(){}

    Pair(int val,int gap){
        this->val=val;
        this->gap=gap;
    }
};

class compare{
    public:
    bool operator()(const Pair &a,const Pair &b){
        if(a.gap==b.gap){
            return a.val<b.val;
        }

        return a.gap<b.gap;
    }
};

vector<int> findClosest(vector<int> &arr, int k, int x){
    //write your code here
    vector<int>ans;
    priority_queue<Pair,vector<Pair>,compare>pq;
    for(int i=0;i<k;i++){
        pq.push(Pair(arr[i],abs(arr[i]-x)));
    }

    for(int i=k;i<arr.size();i++){
        if(pq.top().gap > abs(arr[i]-x)){
            pq.pop();
            pq.push(Pair(arr[i],abs(arr[i]-x)));
        }
        else if(pq.top().gap == abs(arr[i]-x) && pq.top().val>arr[i]){
            pq.pop();
            pq.push(Pair(arr[i],abs(arr[i]-x)));
        }
    }

    while(pq.size()>0){
        int data = pq.top().val;
        ans.push_back(data);
        pq.pop();
    }

    sort(ans.begin(),ans.end());
    return ans;
}

int main(){
    int n;
    cin>>n;
    vector<int> arr;
    
    for(int i=0; i<n; ++i){
        int a;
        cin>>a;
        arr.push_back(a);
    }
    
    int k, x;
    cin>>k>>x;
    
    vector<int> ans=findClosest(arr, k, x);
    
    for(int ele: ans){
        cout<<ele<<" ";
    }
    
    return 0;
}
