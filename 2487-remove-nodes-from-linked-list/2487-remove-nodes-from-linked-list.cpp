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
    ListNode* reverseLinkedList(ListNode* head){
        ListNode* curr = head;
        ListNode* prev = NULL;
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
    ListNode* removeNodes(ListNode* head) {
        ListNode* newHead = reverseLinkedList(head);
        ListNode* curr = newHead;
        ListNode* prev = new ListNode(0);
        while(curr!=NULL){
            if(curr->val>=prev->val){
                prev = curr;
                curr = curr->next;
            }else{
                ListNode* del = curr;
                prev->next = curr->next;
                curr = curr->next;
                delete del;
            }
        }
        return reverseLinkedList(newHead);
    }
};