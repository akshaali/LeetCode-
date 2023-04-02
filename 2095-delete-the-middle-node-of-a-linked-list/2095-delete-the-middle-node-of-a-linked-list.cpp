using namespace std;
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
    ListNode* deleteMiddle(ListNode* head) {
        // no node
        if(!head) return head;
        //1 head
        if(head->next == NULL){
           
            ListNode* ans = head->next;
            delete head;
            return ans;
        }
        ListNode* prev = NULL;
        ListNode* node1x = head;
        ListNode* node2x = head;
        while(node2x!= NULL && node2x->next != NULL){
            prev = node1x;
            node1x = node1x->next;
            node2x = node2x->next ? node2x->next->next : NULL;
        }
        prev->next = node1x->next;
        node1x->next = NULL;
        delete node1x;
        return head;
    }
};