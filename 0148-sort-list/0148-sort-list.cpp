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
    ListNode* midNode(ListNode* head){
        ListNode* slow = head;
        ListNode* fast = head->next;
        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1 == NULL) return list2;
        if(list2 == NULL) return list1;
        ListNode* dummy = new ListNode(-1000001);
        dummy->next = list1;
        ListNode* prev = dummy;
        ListNode* curr = list1;
        ListNode* temp = list2;
        while(curr!=NULL && temp !=NULL){
            if(temp->val>=prev->val && temp->val<=curr->val){
                ListNode* newNode = temp;
                temp = temp->next;
                prev->next = newNode;
                newNode->next = curr;
                prev = prev->next;
            }else{
                prev = prev->next;
                curr = curr->next;
            }
        }
        while(temp!=NULL){
            prev->next = temp;
            temp = temp->next;
            prev = prev->next;
        }
        return dummy->next;
    }
public:
    ListNode* sortList(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;
        ListNode* mid = midNode(head);
        ListNode* left = head;
        ListNode* right = mid->next;
        mid->next = NULL;
        left = sortList(left);
        right = sortList(right);
        ListNode* result = mergeTwoLists(left, right);
        return result;
    }
};