// Last updated: 01/04/2026, 19:26:03
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
    ListNode* middleNode(ListNode* head) {
    vector<ListNode*>ans;
    ListNode* temp = head;
    while(temp!=nullptr){
        ans.push_back(temp);
        temp=temp->next;
    }
    int n = ans.size();
    return ans[n/2];
    }
};