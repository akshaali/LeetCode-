using namespace std;
class MyCircularDeque {
    int* arr;
    int count;
    int front;
    int rear;
    int size;
public:
    MyCircularDeque(int k) {
        arr = new int[k];
        count = 0;
        size = k;
        front = k-1;
        rear = 0;
    }
    
    bool insertFront(int value) {
        if(isFull()) return false;
        count++;
        arr[front] = value;
        front = (front-1+size)%size;
        return true;
    }
    
    bool insertLast(int value) {
        if(isFull()) return false;
        count++;
        arr[rear] = value;
        rear = (rear+1)%size;
        return true;
    }
    
    bool deleteFront() {
        if(isEmpty()) return false;
        count--;
        front = (front+1)%size;
        return true;
    }
    
    bool deleteLast() {
        if(isEmpty()) return false;
        count--;
        rear = (rear-1+size)%size;
        return true;
    }
    
    int getFront() {
        if(isEmpty()) return -1;
        int frontIndex = (front+1)%size;
        return arr[frontIndex];
    }
    
    int getRear() {
        if(isEmpty()) return -1;
        // cout<<"rear: "<<rear<<endl;
        // print();
        int rearIndex = (rear-1+size)%size;
        return arr[rearIndex];
    }
    
    bool isEmpty() {
        return count == 0;
    }
    
    bool isFull() {
        return count == size;
    }
    void print(){
        for(int i = 0; i<size; i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */