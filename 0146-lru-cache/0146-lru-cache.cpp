
class LRUCache {
public:
    class Node {
        public:
            int value;
            int key;
            Node* prev;
            Node* next;
            // Constructor
            Node(int k, int val) {
               value = val;
               key = k; 
               prev = next = nullptr;      
            }
    };
    int capacity = 0;
    Node* head = new Node(-1, -1);
    Node* tail = new Node(-1, -1);
    unordered_map<int, Node*> hash;
    
    void deleteANode(Node* node){
        Node* prev = node->prev;
        Node* next = node->next;
        prev->next = next;
        next->prev = prev;
    }
    
    void insertANodeAtHead(Node* node){
        Node* headNext = head->next;
        head->next = node;
        node->prev = head;
        node->next = headNext;
        headNext->prev = node;
    }
    
    LRUCache(int cap) {
        capacity = cap;
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if(hash.count(key) == 0) return -1;
        Node* node = hash[key];
        deleteANode(node);
        insertANodeAtHead(node);
        return node->value;
    }
    
    void put(int key, int value) {
        if(hash.count(key)){
            Node* node = hash[key];
            node->value = value;
            deleteANode(node);
            insertANodeAtHead(node);
        }else{
            if(hash.size() == capacity){
                Node* lastNode = tail->prev;
                hash.erase(lastNode->key);
                deleteANode(lastNode);
            }
            Node* newNode = new Node(key, value);
            insertANodeAtHead(newNode);
            hash[key] = newNode;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */