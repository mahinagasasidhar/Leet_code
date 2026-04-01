// Last updated: 01/04/2026, 19:27:14
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
      ListNode* temp = node->next;
      node->val=node->next->val;
      node->next=node->next->next;
      delete temp;
    }
};