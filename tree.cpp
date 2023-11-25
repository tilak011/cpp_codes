#include<iostream>
#include<queue>
using namespace std;
class node{
    public:
        int data;
        node*left;
        node*right;
    node(int d){
        this->data=d;
        this->left=NULL;
        this->right=NULL;
    }
};
node* createtree(node*root){
    cout<<"Enter the data"<<endl;
    int data;
    cin>>data;
    root=new node(data);
    if(data==-1){
        return NULL;
    }
    cout<<"Enter the data for inserting it to the left of "<<data<<endl;
    root->left=createtree(root->left);
    cout<<"Enter the data for inserting it to the right of "<<data<<endl;
    root->right=createtree(root->right);
    return root;
}

// creating tree traversal
node*treetraversal(node*root){
    queue<node*>q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        node*temp=q.front();
        q.pop();
        if(temp==NULL){
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
            }

        }else{
            cout<<temp->data<<" ";
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }

    }

} 
int height(node*root,int &maxi){
    if(root==NULL)
        return 0;
    int left=height(root->left,maxi);
    int right=height(root->right,maxi);
    maxi=max(maxi,left+right);
    int ans=max(left,right)+1;
    return ans;
}

void leafnodes(node*root,int &count){
    if(root==NULL){
        return;
    }
    leafnodes(root->left,count);
    if(root->left==NULL && root->right==NULL){
        count++;
    }
    leafnodes(root->right,count);
}
int main(){
    node*root=NULL;
    root=createtree(root);
    // cout<<"Printing the level order traversal"<<endl;
    // treetraversal(root);
    // int h=height(root);
    // cout<<h-1<<endl;
    // int count=0;
    // leafnodes(root,count);
    // cout<<count;
    int maxi=0;
    int h11=height(root->left,maxi);
    int h22=height(root->right,maxi);
    cout<<"hello ji this is your diameter"<<endl;
    cout<<maxi;
    //cout<<h11+h22+3<<endl;
    return 0;
}