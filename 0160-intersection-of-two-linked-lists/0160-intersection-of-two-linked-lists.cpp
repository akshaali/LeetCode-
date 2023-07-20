/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    int lengthList(ListNode *head){
        int length = 0;
        while(head != NULL){
            length++;
            head = head->next;
        }
        return length;
    }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int lenA = lengthList(headA);
        int lenB = lengthList(headB);
        while(lenA>lenB){
            headA = headA->next;
            lenA--;
        }
        while(lenB>lenA){
            headB = headB->next;
            lenB--;
        }
        while(headA != headB){
            headA = headA->next;
            headB = headB->next;
        }
        return headA;   
    }
};