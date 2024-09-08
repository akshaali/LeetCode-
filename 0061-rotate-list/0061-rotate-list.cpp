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
    int lenthLL(ListNode* head){
        int len = 0;
        while(head){
            len++;
            head = head->next;
        }
        return len;
    }
    ListNode* findBeforeTail(ListNode* head){
        while(head && head->next && head->next->next){
            head = head->next;
        }
        return head;
    }
    void printLL(ListNode* head){
        while(head){
            cout<<head->val<<" -> ";
            head = head->next;
        }
        cout<<"NULL"<<endl;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        int len = lenthLL(head);
        if(len == 0 || len == 1 || k == 0){
            // cout<<"head at return==>> "<<endl;
            // printLL(head);
            return head;
        };
        k = k%len;
        if(k == 0) return head;
        ListNode* beforeTail = findBeforeTail(head);
        ListNode* tail = beforeTail->next;
        beforeTail->next = NULL;
        tail->next = head;
        head = tail;
        tail = beforeTail;
        // printLL(head);
        return rotateRight(head, k-1);
    }
};