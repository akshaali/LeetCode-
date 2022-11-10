class Solution {
public:
    int minimumSize(vector<int>& nums, int maxOperations) {
        int low = 1, high = 1e9;
        while(low<high){
            int mid = low + (high-low)/2;
            // cout<<"low: "<<low<<" high: "<< high<<" mid: "<< mid<<endl;
            if(canMinimize(nums, mid, maxOperations)) high = mid;
            else low = mid+1;
        }
        return low;
    }
    bool canMinimize(vector<int> nums, int size, int mxOps){
        for(auto n: nums){
            mxOps -= ((n-1)/size);
            // cout<<"mxOps: "<<mxOps<<"\t";
        }
        // cout<<endl;
        if(mxOps<0) return false;
        return true;
    }
};