class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 0, rec = -1;
        for(auto ele: nums){
            if(count == 0) rec = ele;
            if(ele == rec) count ++;
            else count --;
        }
        return rec;
    }
};