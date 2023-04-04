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
    int lengthOfList(ListNode* head){
        int len = 0;
        while(head != NULL){
            len++;
            head = head->next;
        }
        return len;
    }
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == NULL) return head;
        if(lengthOfList(head)<k) return head;
        int count = 0;
        ListNode* curr = head;
        ListNode* prev = NULL;
        ListNode* next = NULL;
        while(count<k && curr!= NULL){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            count++;
        }
        head->next = reverseKGroup(next, k);
        return prev;
    }
};