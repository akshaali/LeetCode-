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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL || head->next ==NULL) return head;
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* prev = dummy;
        ListNode* curr = head;
        ListNode* next = curr->next;
        while(curr!=NULL && next != NULL){
            if(curr->val == next->val){
                while(curr!=NULL && next!=NULL && curr->val == next->val){
                    curr = next;
                    next = next->next;
                }
                prev->next = next;
            }else{
                prev = prev->next;
            }
            curr = next;
            next = next != NULL ? next->next : NULL;
        }
        
        return dummy->next;
    }
};