/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
    void addAtTail(Node* &head, Node* &tail, int val){
        Node* temp = new Node(val);
        if(head == NULL){
            head = temp;
            tail = temp;
            tail->next = NULL;
        }else{
            tail->next = temp;
            tail = temp;
            tail->next = NULL;
        }
    }
    void mapping(Node* oldL, Node* newL, map<Node*, Node*> &mp){
        while(oldL != NULL){
            mp[oldL] = newL;
            oldL = oldL->next;
            newL = newL->next;
        }
    }
    void copyRandomPointer(Node* oldL, Node* &newL, map<Node*, Node*> mp){
        Node* temp = newL;
        while(oldL != NULL){
            temp->random = mp[oldL->random];
            oldL = oldL->next;
            temp = temp->next;
        }
    }
public:
    Node* copyRandomList(Node* iniHead) {
        Node* head = NULL;
        Node* tail = NULL;
        Node* temp = iniHead;
        map<Node*, Node*>mp;
        while(temp != NULL){
            addAtTail(head, tail, temp->val);
            temp = temp->next;
        }
        mapping(iniHead, head, mp);
        copyRandomPointer(iniHead, head, mp);
        return head;
    }
};