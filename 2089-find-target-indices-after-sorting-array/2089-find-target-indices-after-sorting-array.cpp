


class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
       vector<int> ans;
        int targetCount = 0, smallerElements = 0;
        // we count the number of times the target occurs
        // and the number of elements lesser than target
        for (auto num : nums) {
            if (num == target) targetCount++;
            if (num < target) smallerElements++;
        }
        // If the array were sorted, the target would strart occupying indices from 
        // the number equal to smallerElements (coz 0-indexed) 
        // till (smallerElements + targetCount)
        // That would literally give us all the target indices serially
        
        for (int i = smallerElements; i < smallerElements + targetCount; i++) {
            ans.push_back(i);
        }
        
        return ans;
    };
};