class FrontMiddleBackQueue {
    deque<int> front;
    deque<int> back;
public:
    FrontMiddleBackQueue() {
        
    }
    
    void pushFront(int val) {
        front.push_front(val);
        if(front.size() == back.size() + 2){
            int moveEle = front.back();
            front.pop_back();
            back.push_front(moveEle);
        }
         // print();
    }
    
    void pushMiddle(int val) {
        if(front.size() == back.size() + 1){
            int moveEle = front.back();
            front.pop_back();
            back.push_front(moveEle);
        }
        front.push_back(val);
        // print();
    }
    
    void pushBack(int val) {
        back.push_back(val);
         if(back.size() == front.size() + 1){
            int moveEle = back.front();
            back.pop_front();
            front.push_back(moveEle);
        }
        // print();
    }
    
    int popFront() {
        // print();
        if(front.empty() && back.empty()) return -1;
       int ans = front.front();
        front.pop_front();
         if(back.size() == front.size() + 1){
            int moveEle = back.front();
            back.pop_front();
            front.push_back(moveEle);
        }
        return ans;
    }
    
    int popMiddle() {
         // print();
        if(front.empty() && back.empty()) return -1;
        int ans = front.back();
        front.pop_back();
         if(back.size() == front.size() + 1){
            int moveEle = back.front();
            back.pop_front();
            front.push_back(moveEle);
        }
        return ans;
    }
    
    int popBack() {
        // print();
        if(front.empty() && back.empty()) return -1;
        if(back.empty() && !front.empty()){
            int ans = front.back();
            front.pop_back();
            return ans;
        }
        int ans = back.back();
        back.pop_back();
         if(front.size() == back.size() + 2){
            int moveEle = front.back();
            front.pop_back();
            back.push_front(moveEle);
        }
        return ans;
    }
    void print(){
        deque<int> printF = front;
        deque<int> printB = back;
         cout<<endl;
        cout<<"front: ";
        while(!printF.empty()){
            cout<<printF.front()<<" ";
            printF.pop_front();
        }
        cout<<endl;
        cout<<"back: ";
        while(!printB.empty()){
            cout<<printB.front()<<" ";
            printB.pop_front();
        }
        cout<<endl;
    }
};

/**
 * Your FrontMiddleBackQueue object will be instantiated and called as such:
 * FrontMiddleBackQueue* obj = new FrontMiddleBackQueue();
 * obj->pushFront(val);
 * obj->pushMiddle(val);
 * obj->pushBack(val);
 * int param_4 = obj->popFront();
 * int param_5 = obj->popMiddle();
 * int param_6 = obj->popBack();
 */