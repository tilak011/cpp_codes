/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
private:
    ListNode*reverse(ListNode*back){
        ListNode*curr=back;
        ListNode*forw=NULL;
        ListNode*prev=NULL;
        while(curr!=NULL){
            forw=curr->next;
            curr->next=prev;
            prev=curr;
            curr=forw;
        }
        return prev;

       
    }
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(head==NULL){
            return NULL;
        }
        if(left==right){
            return head;
        }int ll=1,rr=1;
        ListNode*back=head;
        ListNode*front=head;
        while(ll<left){
            back=back->next;
            ll++;
        }
        while(rr<right){
            front=front->next;
            rr++;
        }
        ListNode*front2=front->next;
        front->next=NULL;
        ListNode*local_back=reverse(back);
        head->next=local_back;
        ListNode*local_head=head;
        while(local_head->next!=NULL){
            local_head=local_head->next;
        }
        local_head->next=front2;
        return head;

        
    }
};