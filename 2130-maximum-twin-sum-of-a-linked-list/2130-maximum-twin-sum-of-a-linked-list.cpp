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
        int length = 0;
        while(head != NULL){
            head = head->next;
            length++;
        }
        return length;
    }
    int pairSum(ListNode* head) {
        stack<int> st;
        int ans = INT_MIN;
        int halfLen = lengthList(head)/2;
        while(halfLen){
            st.push(head->val);
            head = head->next;
            halfLen--;
        }
        while(head!=NULL){
            int ele = st.top();
            st.pop();
            ans = max(ans, ele+head->val);
            head = head->next;
        }
        return ans;
    }
};