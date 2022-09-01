class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> majority;
        int maj1=INT_MIN, maj2=INT_MIN, count1=0, count2=0;
        for(auto ele: nums){
            if(maj1 == ele) count1++;
            else if(maj2 == ele) count2++;
            else if(count1 == 0){ 
                maj1 = ele;
                count1++;
            }
            else if(count2 == 0){
                 maj2 = ele;
                count2++;
            }
            else{
                count1--;
                count2--;
            }
        }
        int maj = nums.size()/3;
        count1 = 0, count2 = 0;
        for(auto ele: nums){
            if(ele == maj1) count1++;
            if(ele == maj2) count2++;
        }
        if(count1>maj) majority.push_back(maj1);
        if(count2>maj) majority.push_back(maj2);
        return majority;
        
    }
};