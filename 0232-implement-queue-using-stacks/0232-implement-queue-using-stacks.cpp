using namespace std;
class MyQueue {
    stack<int>inSt, outSt;
public:
    MyQueue() {
        
    }
    
    void push(int x) {
        inSt.push(x);
    }
    
    int pop() {
        int ans = peek();
        outSt.pop();
        return ans;
    }
    
    int peek() {
        if(outSt.empty()){
            while(!inSt.empty()){
                outSt.push(inSt.top());
                inSt.pop();
            }
        }
        return outSt.top();
    }
    
    bool empty() {
        cout<<inSt.empty()<<" "<<outSt.empty()<<endl;
        if(inSt.empty() && outSt.empty()) return true;
        return false;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */