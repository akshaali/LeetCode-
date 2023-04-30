using namespace std;
class MedianFinder {
public:
    //max heap 8,3,4
    priority_queue<int> firstHalf;
    //min heap 1,2,3
    priority_queue <int, vector<int>, greater<int> > nextHalf;
    
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        firstHalf.push(num);
        if(firstHalf.size()==nextHalf.size()+1){
            if(nextHalf.size() && nextHalf.top()<firstHalf.top()){
                int maxOfFirst = firstHalf.top();
                int minOfNext = nextHalf.top();
                firstHalf.pop();
                nextHalf.pop();
                firstHalf.push(minOfNext);
                nextHalf.push(maxOfFirst);
            }
        }
        if(firstHalf.size()==nextHalf.size()+2){
            int topOfFirst = firstHalf.top();
            firstHalf.pop();
            nextHalf.push(topOfFirst);
        }
    }
    
    double findMedian() {
        int sizeOfFirst = firstHalf.size();
        int sizeOfNext = nextHalf.size();
        double median;
        if((sizeOfFirst+sizeOfNext)%2 == 0){
            median = (double)(firstHalf.top() + nextHalf.top())/2;
            
        }else{
            median= firstHalf.top();
        }
        return median;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */