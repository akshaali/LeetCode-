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
    int lengthList(ListNode* head){
        int len = 0;
        while(head){
            len++;
            head = head->next;
        }
        return len;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        int n = lengthList(head);
        if(n== 0) return head;
        k = k%n;
        if(k == 0) return head;
        ListNode* headCopy = head;
        ListNode* newHead = NULL;
        ListNode* newTail = NULL;
        ListNode* tail = NULL;
        int count = n-k;
        while(headCopy->next != NULL){
            if(count == 1){
                newHead = headCopy->next;
                newTail = headCopy;
            }
            count--;
            headCopy = headCopy->next;
        }
        tail = headCopy;
        newTail->next = NULL;
        tail->next = head;
        return newHead;
    }
};