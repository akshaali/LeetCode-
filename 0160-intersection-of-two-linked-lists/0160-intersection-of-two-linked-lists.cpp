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
    int getLengthLL(ListNode *head){
        int len = 0;
        while(head){
            len++;
            head = head->next;
        }
        return len;
    }
    ListNode* colisionNode(ListNode* headA, ListNode* headB, int len){
        ListNode* tempA = headA;
        ListNode* tempB = headB;
        while(len){
            tempA = tempA->next;
            len--;
        }
        while(tempA && tempB && tempA != tempB){
            tempA = tempA->next;
            tempB = tempB->next;
        }
        return tempA;
    }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* tempA = headA;
        ListNode* tempB = headB;
        int lenA = getLengthLL(tempA);
        int lenB = getLengthLL(tempB);
        if(lenA>lenB){
            return colisionNode(headA, headB, lenA-lenB);
        }
        return colisionNode(headB, headA, lenB-lenA);
    }
};