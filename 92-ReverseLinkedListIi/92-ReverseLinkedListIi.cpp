// Last updated: 01/04/2026, 19:28:21
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
public:
    ListNode*reverse(ListNode* head, int left, int right,ListNode*dummy){
    ListNode*temp=head;
    ListNode*tempa=head;
    ListNode*prev=nullptr;
    for(int i = 0;i<right-left+1;i++){
      temp=temp->next;
      head->next=prev;
      prev=head;
      head=temp;
    }
    dummy->next=prev;
    tempa->next=head;
    return dummy;
    }
    ListNode* reverseBetween(ListNode* head, int left, int right) {
    if(head==nullptr||left==right){
        return head;
    }
    ListNode*dummy=new ListNode();
    dummy->next=head;
    ListNode*temp=dummy;
    for(int i=1;i<left;i++){
    temp=temp->next;
    }
   reverse(temp->next,left,right,temp);
   return dummy->next;
    }
};