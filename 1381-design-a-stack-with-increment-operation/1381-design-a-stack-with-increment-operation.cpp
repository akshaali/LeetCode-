class CustomStack {
public:
    int *arr;
    int top;
    int size;
    CustomStack(int maxSize) {
        arr = new int[maxSize];
        size = maxSize;
        top = -1;
    }
    
    void push(int x) {
        if(size-top>1){
            arr[++top] = x;
        }
    }
    
    int pop() {
        if(top>=0){
            return arr[top--];
        }else{
            return -1;
        }
        // return 0;
    }
    
    void increment(int k, int val) {
        if(top>=0){
             int count = 0;
            while(count<k && count<=top){
            arr[count++] += val;
            }
        }
       
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */