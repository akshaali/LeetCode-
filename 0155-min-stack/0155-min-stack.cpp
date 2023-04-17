using namespace std;
class MinStack {
public:
    vector<long int> arr;
    int size = 0;
    long int mini = INT_MAX;
    MinStack() {
    }
    void print(){
        for(int i = 0; i<arr.size(); i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
    
    void push(int val) {
        if(size == 0){
            arr.push_back(val);
            mini = val;
        }else{
            long int data = val-mini;
            arr.push_back(data);
            if(val<mini) mini = val;
        }
        size++;
    }
    
    void pop() {
        long int top = arr[size-1];
        if(top<0){
           long int oldMini = mini - top;
            mini = oldMini;
             arr.pop_back();
        }else{
             arr.pop_back();
        }
        size--;
    }
    
    int top() {
        long int top_ = arr[size-1];
        // cout<<"top_ "<<top_<<" mini "<<mini<<endl;
        if(top_< 0){
           return mini;
        }else{
            if(size == 1) return top_;
            long int data = int(top_ + mini);
            // print();
            // cout<<"data "<<data<<endl;
             return data;
        }
    }
    
    int getMin() {
        return (long)mini;
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