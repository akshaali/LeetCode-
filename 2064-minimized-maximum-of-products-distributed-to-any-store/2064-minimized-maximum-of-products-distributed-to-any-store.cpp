using namespace std;
class Solution {
public:
    int minimizedMaximum(int n, vector<int>& quantities) {
        int low = 1, high = *max_element(quantities.begin(), quantities.end());
        while(low<high){
            int mid = low + (high-low)/2;
            if(canDistribute(quantities, mid, n)){
                low = mid+1;
            }else{
                high = mid;
            }
            
        }
        return low;
    }
    bool canDistribute(vector<int> quantities, int x, int n){
        for(auto val : quantities){
            n -= ceilVal(val, x);
        }
        if(n<0) return true;
        return false;
    }
    int ceilVal(int a, int b){
        return (a / b) + ((a % b) != 0);
    }
};