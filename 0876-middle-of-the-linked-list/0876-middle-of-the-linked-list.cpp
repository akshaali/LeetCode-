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
        if(!head) return head;
        if(head->next == NULL) return head;
        ListNode* node1x = head;
        ListNode* node2x = head;
        while(node2x!= NULL && node2x->next != NULL){
            node1x = node1x->next;
            node2x = node2x->next ? node2x->next->next : NULL;
        }
        return node1x;
    }
};