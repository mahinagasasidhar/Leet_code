// Last updated: 01/04/2026, 19:27:47
class Solution {
public:
    ListNode*merge(ListNode*left,ListNode*right){
    ListNode*dummy = new ListNode(0);
    ListNode*ans=dummy;
    while(left!=nullptr && right!=nullptr){
    if(left->val < right->val){
    ans->next=left;
    ans=left;
    left=left->next;
    }
        else{
        ans->next=right;
        ans=right;
        right=right->next; 
        }
    }
    while(left){
    ans->next=left;
    ans=left;
    left=left->next; 
    }
    while(right){
    ans->next=right;
    ans=right;
    right=right->next;    
    }
    return dummy->next;
    }
    ListNode* findmiddle(ListNode*head){
        ListNode*slow=head;
        ListNode*fast=head->next;
        while(fast!=nullptr&&fast->next!=nullptr){
        slow=slow->next;
        fast=fast->next->next;
        }
        return slow;
    }
    ListNode* sortList(ListNode* head) {
    if(head==nullptr||head->next==nullptr){
        return head;
    }
    ListNode* middle = findmiddle(head);
    ListNode*right=middle->next;
    middle->next=nullptr;
    ListNode*left=head;
    left = sortList(left);
    right = sortList(right);
    return merge(left,right);
    }
};