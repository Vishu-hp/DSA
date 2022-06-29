#include<bits/stdc++.h>
#include<iostream>

using namespace std;

int binary_search(vector<int>&arr,int x){
    int lo=0,hi=arr.size()-1;
    int mid;
    while(lo<=hi){
        mid = (lo+hi)/2;

        if(arr[mid]==x){
            return mid;
        }

        if(arr[mid]<x){
            lo=mid+1;
        }
        else{
            hi=mid-1;
        }
    }
    return mid;
}

vector<int> findClosest(vector<int> &arr, int k, int x){
    //write your code here
    int closest = binary_search(arr,x);
    int lo=closest-1,hi=closest;

    vector<int>ans;
    int cnt=0;
    while(lo>=0 && hi<arr.size() && cnt<k){
        if(abs(arr[lo]-x) <= abs(arr[hi]-x)){
            ans.push_back(arr[lo]);
            lo--;
        }
        else{
            ans.push_back(arr[hi]);
            hi++;
        }
        cnt++;
    }

    while(cnt<k && lo>=0){
        ans.push_back(arr[lo]);
        lo--;
        cnt++;
    }

    while(cnt<k && hi<arr.size()){
        ans.push_back(arr[hi]);
        hi++;
        cnt++;
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
