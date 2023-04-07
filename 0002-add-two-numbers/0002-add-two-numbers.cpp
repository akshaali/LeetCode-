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
private:
    ListNode* reverseList(ListNode* head){
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* next = NULL;
        while(curr != NULL){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    void addAtTail(ListNode* &head, ListNode* &tail, int val){
        ListNode* temp = new ListNode(val);
        if(head == NULL){
            head = temp;
            tail = temp;
            return;
        }
        tail->next = temp;
        tail = temp;
    }
    void printList(ListNode* head){
        while(head != NULL){
            cout<< head->val<<" ";
            head = head->next;
        }
        cout<<endl;
    }
    ListNode* addNode(ListNode*l1, ListNode* l2){
        ListNode* head = NULL;
        ListNode* tail = NULL;
        int carry = 0;
        while(l1!=NULL && l2!=NULL){
            int sum = l1->val + l2->val + carry;
            int digit = sum % 10;
            carry = sum /10;
            addAtTail(head, tail, digit);
            l1 = l1->next;
            l2 = l2->next;
        }
    while(l1 != NULL){
        int sum = l1->val + carry;
        int digit = sum % 10;
        carry = sum /10;
        addAtTail(head, tail, digit);
        l1 = l1->next;
    }
    while(l2 != NULL){
        int sum = l2->val + carry;
        int digit = sum % 10;
        carry = sum /10;
        addAtTail(head, tail, digit);
        l2 = l2->next;
    }
    if(carry){
         addAtTail(head, tail, carry);
    }
      return head;
    }
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // l1 = reverseList(l1);
        // l2 = reverseList(l2);
        // printList(l1);
        // printList(l2);
        ListNode* ans = addNode(l1,l2);
        // ans = reverseList(ans);
        return ans;
    }
};






