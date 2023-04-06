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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        int currPosition = 1;
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* curr = head;
        ListNode* prev = dummy;
        ListNode* next = NULL;
        ListNode* temp = NULL;
        while(currPosition<left){
            prev = curr;
            curr = curr->next;
            currPosition++;
        }
        while(currPosition<right){
            next = curr->next;
            temp = prev->next;
            prev->next = next;
            curr->next = next->next;
            next->next = temp;
            currPosition++;
        }
        return dummy->next;
        
    }
};