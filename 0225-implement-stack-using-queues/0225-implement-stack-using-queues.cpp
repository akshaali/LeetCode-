class MyStack {
    deque<int> input;
public:
    MyStack() {
        
    }
    
    void push(int x) {
        input.push_back(x);
    }
    
    int pop() {
        int ans = input.back();
        input.pop_back();
        return ans;
    }
    
    int top() {
        int ans = input.back();
        return ans;
    }
    
    bool empty() {
        return input.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */