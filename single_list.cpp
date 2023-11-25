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
void insertatfront(node* &head,int d){
    node*n2=new node(d);
    n2->next=head;
    head=n2;
    
}
void print(node*&head){
    node*temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }

}
void deleteatfront(node*&head){
    node*temp=head;
    temp=temp->next;
    head->next=NULL;
    head=temp;
}
void deleteatend(node*&head){
    node*temp=head;
    while(temp->next->next!=NULL){
        temp=temp->next;
    }
    temp->next=NULL;

}
void reverse(node*&head){
    node*curr=head;
    node*prev=NULL;
    node*neww=NULL;
    while(curr!=NULL){
        neww=curr->next;
        curr->next=prev;
        prev=curr;
        curr=neww;
    }
    head=prev;
}
int main(){
    node *n1=new node(10);
    //cout<<n1->data<<" ";
    node*head=n1;
    insertatfront(head,33);
    insertatfront(head,87);
    insertatfront(head,45);
    insertatfront(head,89);
    insertatfront(head,100);
    // deleteatfront(head);
    // deleteatend(head);
    cout<<"before reveral "<<endl;
    print(head);
    cout<<endl;
    cout<<"after reversal"<<endl;
    reverse(head);
    print(head);
    return 0;

}

