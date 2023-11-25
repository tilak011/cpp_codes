#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main(){
    stack<int>s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    s.push(6);
    // while(!s.empty()){
    //     cout<<s.top()<<" ";
    //     s.pop();
    // }
    stack<int>rev;
    while(!s.empty()){
        rev.push(s.top());
        s.pop();
    }
    while(!rev.empty()){
        cout<<rev.top()<<" ";
        rev.pop();
    }
    
}