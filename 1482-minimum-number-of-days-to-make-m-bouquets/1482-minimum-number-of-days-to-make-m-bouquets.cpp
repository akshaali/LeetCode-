class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        if(n< (long long )m*k) return -1;
        int low = *min_element(bloomDay.begin(), bloomDay.end());
        int high = *max_element(bloomDay.begin(), bloomDay.end());
        while(low<high){
            int mid = low + (high-low)/2;
            if(canHarvest(bloomDay, mid, m, k)){
                high = mid;
            }else{
                low = mid+1;
            }
            
        }
        return low;

        
    }
    
    bool canHarvest(vector<int> bloomDay, int harvestDay, int m , int k){
        int adjacent = 0;
        for(auto bloomed: bloomDay){
            adjacent = bloomed <= harvestDay ? adjacent + 1 : 0;
            if(adjacent == k){
                m--;
                adjacent = 0;
            }
        }
        return m <= 0;
    }
};