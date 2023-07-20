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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* ans = NULL;
        bool flag = false;
        unordered_map<ListNode*, int> mp;
        while(headA && headB){
            if(mp[headA]){
                ans = headA;
                return ans;
            }else{
                mp[headA]++;
            }
            if(mp[headB]){
                ans = headB;
                return ans;
            }else{
                mp[headB]++;
            }
            headA = headA->next;
            headB = headB->next;
        }
        while(headA){
            if(mp[headA]){
                ans = headA;
                return ans;
            }else{
                mp[headA]++;
            }
            headA = headA->next;
        }
        while(headB){
            if(mp[headB]){
                ans = headB;
                return ans;
            }else{
                mp[headB]++;
            }
            headB = headB->next;
        }
        return ans;   
    }
};