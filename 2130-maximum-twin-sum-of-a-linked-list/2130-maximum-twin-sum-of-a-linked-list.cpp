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
    int pairSum(ListNode* head) {
        int ans = INT_MIN;
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* node = NULL;
        while(slow != NULL){
            ListNode* next = slow->next;
            slow->next = node;
            node = slow;
            slow = next;
        }
        while(node!=NULL){
            ans = max(ans, node->val+head->val);
            head = head->next;
            node = node->next;
        }
        return ans;
    }
};