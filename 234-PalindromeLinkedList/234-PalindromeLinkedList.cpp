// Last updated: 01/04/2026, 19:27:16
class Solution {
public:
   ListNode*reverse(ListNode*head){
   if(head==nullptr||head->next==nullptr){
    return head;
   }
   ListNode*newhead=reverse(head->next);
   ListNode*front=head->next;
   front->next=head;
   head->next=nullptr;
   return newhead;
   }
    bool isPalindrome(ListNode* head) {
    if(head->next==nullptr){
        return true;
    }
    ListNode*slow=head;
    ListNode*fast=head;
    while(fast->next!=nullptr&&fast->next->next!=nullptr){
        slow=slow->next;
        fast=fast->next->next;
    }
    ListNode*first=head;
    ListNode*second=reverse(slow->next);
    while(second){
        if(first->val!=second->val){
            return false;
        }
        first=first->next;
        second=second->next;    
    }
    reverse(slow->next);
    return true;
    }
};