class BrowserHistory {
public:
    class Node{
    public:
    string url;
    Node* next;
    Node* prev;
    Node(string _val){
        this->url = _val;
        this->next = NULL;
        this->prev = NULL;
    }
    };
    Node* head = NULL;
    Node* curr = NULL;
    BrowserHistory(string homepage) {
        Node* newNode = new Node(homepage);
        head = newNode;
        curr = head;
    }
    void visit(string url) {
        Node* newNode = new Node(url);
        curr->next = newNode;
        newNode->prev = curr;
        newNode->next = NULL;
        curr = newNode;
    }
    string back(int steps) {
        while(curr->prev != NULL && steps-->0){
            curr = curr->prev;
        }
        return curr->url;
    }
    
    string forward(int steps) {
        while(curr->next != NULL && steps-->0){
            curr = curr->next;
        }
        return curr->url;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */