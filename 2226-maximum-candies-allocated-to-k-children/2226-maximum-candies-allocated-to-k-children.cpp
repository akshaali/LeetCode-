using namespace std;
class Solution {
public:
    int maximumCandies(vector<int>& candies, long long k) {
        int high =  1e7;
        int low = 0;
        while(low<high){
            long long mid = (low+high+1)/2;
            // cout<<"low: "<<low<<" high: "<<high<<endl;
            if(canMaximise(candies, mid, k)){
                low = mid;
            }else high = mid-1;
        }
        return low;
        
    }
    bool canMaximise(vector<int> candies, long long maxCandy, long long k){
        // cout<<"maxCandy: "<<maxCandy<<" k: "<<k<<endl;
        for(auto candy: candies){
            k -= (candy/maxCandy);
            // cout<<"remaining K: "<<k<<endl;
        }
        if(k<=0) return true;
        return false;
    }
};