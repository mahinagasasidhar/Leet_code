// Last updated: 01/04/2026, 19:26:56

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
    if(head==nullptr){
        return head;
    }
    if(head->next==nullptr){
        return head;
    }
    ListNode*first=head;
    ListNode*second=head->next;
    ListNode*secondhead=head->next;
    while(second!=nullptr && second->next!=nullptr){
    first->next=second->next;
    first=first->next;
    second->next=first->next;
    second=second->next;
    }
    first->next=secondhead;
    return head;
    }
};