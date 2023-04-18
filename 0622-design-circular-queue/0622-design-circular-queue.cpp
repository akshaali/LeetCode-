using namespace std;
class MyCircularQueue {
    int* arr;
    int front = -1;
    int rear = 0;
    int size;
public:
    MyCircularQueue(int k) {
        arr = new int[k];
        size = k;
    }
    
    bool enQueue(int value) {
        // cout<<isFull()<<endl;
        if(isFull())return false;
        if(rear == size){
            rear = 0;
            arr[rear++] = value;
        }else{
            if(front == -1) front++;
            arr[rear++] = value;
        }
        return true;
    }
    
    bool deQueue() {
        if(isEmpty()) return false;
        if(front == rear-1) { //single element is present
            front =-1;
            rear = 0;
        }else if(front == size-1) {
            front = 0;
        }else{
            front++;
        }
        return true;
    }
    
    int Front() {
         if(isEmpty()) return -1;
        return arr[front];
    }
    
    int Rear() {
        if(isEmpty()) return -1;
        return arr[rear-1];
    }
    
    bool isEmpty() {
        if(front == -1) return true;
        return false;
    }
    
    bool isFull() {
        // cout<<front<<" "<<rear<<endl;
        if(front == 0 && rear == size) return true;
        else if(rear == front) return true;
        return false;   
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */