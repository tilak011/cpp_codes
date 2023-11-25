#include<iostream>
using namespace std;
class node{
    public:
    int data;
    node*next;
    node(int data){
        this->data=data;
        this->next=NULL;
    }

};
void insertatfront(node*&head,int num){
    node*n=new node(num);
    n->next=head;
    head=n;
    
}
void display(node*&head){
    node*temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}
void reverse(node*&head){
   node*prev=NULL;
   node*curr=head;
   node*forward=NULL;
   while(curr!=NULL){
    forward=curr->next;
    curr->next=prev;
    prev=curr;
    curr=forward;
   }
   head=prev;
   //return prev;

}
node*reversefrompointer(node*temp){
    node*local=temp->next;
    temp->next=NULL;
    node*prev=NULL;
    node*forw=NULL;
    while(local!=NULL){
        forw=local->next;
        local->next=prev;
        prev=local;
        local=forw;
    }
    return prev;



}
int main(){
    node*nn=new node(21);
    node*head=nn;
    
    insertatfront(head,40);
    insertatfront(head,70);
    insertatfront(head,80);
    insertatfront(head,10);
    insertatfront(head,20);
    insertatfront(head,90);
    insertatfront(head,30);
    node*local=head;
    cout<<"So this is before reversal"<<endl;
    display(head);
    node*head1=head;
    while(head1->data!=40){
        head1=head1->next;
    }
    // reverse(head);
    // cout<<endl;
    // cout<<"And this is after reversal"<<endl;
    display(head);
    //length(head);
    cout<<endl;
    node*tt=reversefrompointer(head1->next);
    head1=tt;
    display(head);






    return 0;

}