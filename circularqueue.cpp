#include<iostream>
using namespace std;
class circularqueue{
    int *arr;
    int front;
    int rear;
    int size;
public:
    circularqueue(int n){
        arr=new int[n];
        size=n;
        front=-1;
        rear=-1;
    }
    bool isempty(){
        if(front==-1 && rear==-1){
            return true;
        }
        return false;
    }
    bool isfull(){

    }
