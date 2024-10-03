class LFUCache {
public:
    class Node {
        public:
            int value;
            int key;
            int freq;
            Node* prev;
            Node* next;
            // Constructor
            Node(int k, int val) {
               value = val;
               key = k; 
               freq = 1;
               prev = next = nullptr;      
            }
    };
    class List {
        public:
            int size;
            Node* head;
            Node* tail;
            // Constructor
            List(){
               head = new Node(-1, -1);
               tail = new Node(-1, -1);
               head->next = tail;
               tail->prev = head;
               size = 0;
            }
            void deleteANode(Node* node){
                Node* prev = node->prev;
                Node* next = node->next;
                prev->next = next;
                next->prev = prev;
                size--;
            }

            void insertANodeAtHead(Node* node){
                Node* headNext = head->next;
                head->next = node;
                node->prev = head;
                node->next = headNext;
                headNext->prev = node;
                size++;
            }
    };
    
    int maxSizeCache;
    int currentCapacity;
    int minFreq;
    unordered_map<int, Node*> keyNode;
    unordered_map<int, List*> freqListMap;
    
    void updateFreqListMap(Node* node){
        keyNode.erase(node->key);
        freqListMap[node->freq]->deleteANode(node);
        if(node->freq == minFreq && freqListMap[node->freq]->size == 0){
            minFreq++;
        }
        List* nextHigherFreqList = new List();
        if(freqListMap.find(node->freq + 1) != freqListMap.end()){
            nextHigherFreqList = freqListMap[node->freq + 1];
        }
        node->freq +=1;
        nextHigherFreqList->insertANodeAtHead(node);
        freqListMap[node->freq] = nextHigherFreqList;
        keyNode[node->key] = node;
    }
    
    LFUCache(int cap) {
        maxSizeCache = cap;
        currentCapacity = 0;
        minFreq = 0;
    }
    
    int get(int key) {
        if(keyNode.count(key) == 0) return -1;
        Node* node = keyNode[key];
        updateFreqListMap(node);
        return node->value;
    }
    
    void put(int key, int value) {
        if(keyNode.count(key)){
            Node* node = keyNode[key];
            node->value = value;
            updateFreqListMap(node);
        }else{
            if(currentCapacity == maxSizeCache){
                List* list = freqListMap[minFreq];
                keyNode.erase(list->tail->prev->key);
                freqListMap[minFreq]->deleteANode(list->tail->prev);
                currentCapacity--;
            }
            currentCapacity++;
            minFreq = 1;
            List* listFreq = new List();
            if(freqListMap.find(minFreq) != freqListMap.end()){
                listFreq = freqListMap[minFreq];
            }
            Node* newNode = new Node(key, value);
            listFreq->insertANodeAtHead(newNode);
            keyNode[key] = newNode;
            freqListMap[minFreq] = listFreq;
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */