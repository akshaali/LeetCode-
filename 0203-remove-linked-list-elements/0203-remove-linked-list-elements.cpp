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
    ListNode* removeElements(ListNode* head, int val) {
        //if head
        if(!head) return head;
        while(head != NULL && head->val == val){
            ListNode* del = head;
            head = head->next;
            delete del;
        }
        ListNode* prev = NULL;
        ListNode* curr = head;
        while(curr != NULL){
            if(curr->val == val){
                ListNode* del = curr;
                prev->next = curr->next;
                curr = curr->next;
                delete del;
            }else{
                prev = curr;
                curr = curr->next;
            }
            
        }
        // if(curr->val == val){
        //     prev->next = curr->next;
        //     delete curr;
        // }
        return head;
    }
};