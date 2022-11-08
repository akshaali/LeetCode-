class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int low = 1, high = *max_element(piles.begin(), piles.end());
        if(n == h) return high;
        while(low<high){
            int mid = low + (high - low) /2;
            // cout<<"low: "<<low<<" high: "<<high<<endl;
            if(canMinimize(piles, mid, h)){
                high = mid;
            }else{
                low = mid+1;
            }
        }
        return low;
        
    }
    bool canMinimize(vector<int> piles, int k, int h){
        // cout<<"k: "<<k<<" h: "<<h<<endl;
        for(auto banana: piles){
            h -= ceilVal(banana, k);
            // cout<<"values of h: "<<h<<endl;
        }
        if(h>=0) return true;
        return false;
    }
    int ceilVal(int a, int b){
        return (a / b) + ((a % b) != 0);
    }
};