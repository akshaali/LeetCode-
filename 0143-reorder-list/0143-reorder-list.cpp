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
private:
    ListNode* midList(ListNode* head){
        ListNode* slow = head;
        ListNode* fast = head->next;
        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    ListNode* reverseList(ListNode* head){
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* next = NULL;
        while(curr != NULL){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
public:
    void reorderList(ListNode* head) {
        if(head==NULL || head->next == NULL) return;
        ListNode* mid = midList(head);
        ListNode* second = mid->next;
        mid->next = NULL;
        second = reverseList(second);
        ListNode* curr = head;
        while(second!=NULL && curr != NULL){
            ListNode* temp = curr->next;
            ListNode* tempSec = second->next;
            curr->next = second;
            second->next = temp;
            second = tempSec;
            curr = temp;
        }
    }
};