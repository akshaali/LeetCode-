class MinStack {
public:
    vector<int> arr;
    int peek=-1;
    int size=0;
    MinStack() {
        // int *arr;
        // int top=-1;
        // int size=0;
    }
    
    void push(int val) {
        arr.push_back(val);
        peek++;
        size++;
    }
    
    void pop() {
        arr.pop_back();
        size--;
        peek--;
    }
    
    int top() {
        return arr[peek];
    }
    
    int getMin() {
        int min_ = INT_MAX;
        for(int i=0; i<size; i++){
            if(arr[i]<min_){
                min_=arr[i];
            }
        }
        return min_;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */