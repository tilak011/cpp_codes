#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class heap{
    public:
    int ar[100];
    int size;
    heap(){
        ar[0]=-1;
        size=0;
    }
    void insert(int value){
        size=size+1;
        int index=size;
        ar[index]=value;
        while(index>1){
            int parent=index/2;
            if(ar[parent]<ar[index]){
                swap(ar[parent],ar[index]);
                index=parent;
            }else{
                return;
            }

        }
    }
    void print(){
        for(int i=1;i<=size;i++){
            cout<<ar[i]<<" ";
        }cout<<endl;
    }
    void deletefromheap(){
        if(size==0){
            return;
        }else{
            //swap(ar[1],ar[size]);
            ar[1]=ar[size];
            size--;
            int i=1;
            while(i<size){
                int leftside=2*i;
                int rightside=2*i+1;
                if(leftside<size && ar[i]<ar[leftside]){
                    swap(ar[i],ar[leftside]);
                    i=leftside;
                }
                else if(rightside<size && ar[i]<ar[rightside]){
                    swap(ar[i],ar[rightside]);
                    i=rightside;
                }else{
                    return;
                }
            }
        }
    }
};
void heapify(int ar[],int n,int i){
    int largest=i;
    int left=2*i;
    int right=2*i+1;
    if(left<n && ar[largest]<ar[left]){
        largest=left;
    }
    if(right<n && ar[largest]<ar[right]){
        largest=right;
    }
    if(largest!=i){
        swap(ar[largest],ar[i]);
        heapify(ar,n,largest);
    }
}
int main(){
    heap h;
    h.insert(40);
    h.insert(30);
    h.insert(10);
    h.insert(0);
    h.insert(70);
    h.insert(50);
    h.insert(20);
    //cout<<"before deleting any element"<<endl;
    h.print();
    int arr[6]={-1,54,53,55,52,50};
    int n=5;

    //to create heap
    for(int i=n/2;i>0;i--){
        heapify(arr,n,i);
    }


    for(int i=1;i<=n;i++){
        cout<<arr[i]<<" ";
    }cout<<endl;
    // cout<<"Enter the elements to be deleted";
    // int t;
    // cin>>t;
    // cout<<"After deletion the heap looks like"<<endl;
    // while(t--){
    //     h.deletefromheap();
    //     h.print();
    // }

    //now we will use priority queue which is default MAXHEAP;
    priority_queue<int>pq;
    pq.push(1);
    pq.push(5);
    pq.push(7);
    pq.push(2);
    pq.push(3);
    pq.push(4);
    pq.push(0);
    cout<<"the top element is "<<pq.top();

    //now here comes a default min heap which is =>
    priority_queue<int,vector<int>,greater<int>>minhp;
    minhp.push(10);
    minhp.push(0);
    minhp.push(1);
    minhp.push(20);
    minhp.push(15);
    minhp.push(11);
    minhp.push(13);
    cout<<"now the first element of our newely formed min heap is :- "<<minhp.top();
    
    return 0;
}
/* ok so all the leaf nodes lies between (n/2 +1 )th node to nth node..*/