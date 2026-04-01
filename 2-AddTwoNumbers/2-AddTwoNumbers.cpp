// Last updated: 01/04/2026, 19:29:21
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    int val = 0;
    int carry =0;
    ListNode *dummy=new ListNode(0);
    ListNode*curr=dummy;
    while(l1!=nullptr||l2!=nullptr||carry>0){
    int sum =carry; 
    if(l1){
        sum+=l1->val;
        l1=l1->next;
    }
     if(l2){
        sum+=l2->val;
        l2=l2->next;
    }
    carry=sum/10;
    ListNode*temp=new ListNode(sum%10);
    curr->next=temp;
    curr=temp;
    }
    return dummy->next;
    }
};