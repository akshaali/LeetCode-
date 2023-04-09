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
ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1 == NULL) return list2;
        if(list2 == NULL) return list1;
        ListNode* dummy = new ListNode(-100001);
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
         if (lists.empty()) return NULL;
        int len = lists.size();
        while (len > 1) {
            for (int i = 0; i < len / 2; ++i) {
                lists[i] = mergeTwoLists(lists[i], lists[len - 1 - i]);
            }
            len = (len + 1) / 2;
        }
        return lists.front();
    }
};