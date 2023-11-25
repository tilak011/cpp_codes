#include<iostream>
#include<bits/stdc++.h>
using namespace std;
void pattern(int ind,vector<int>&ds,int s,int sum,int n,int arr[]){
    if(ind==n){
        if(s==sum){
            for(auto it:ds) cout<<it<<" ";
            cout<<endl;
        }
        return ;
    }
    
    ds.push_back(arr[ind]);
    s+=arr[ind];
    pattern(ind+1,ds,s,sum,n,arr);
    s-=arr[ind];
    ds.pop_back();
    pattern(ind+1,ds,s,sum,n,arr);
}

int main(){
    int ar[3]={1,2,1};
    int sum=2,n=3;
    vector<int>ds;
    pattern(0,ds,0,sum,n,ar);
}