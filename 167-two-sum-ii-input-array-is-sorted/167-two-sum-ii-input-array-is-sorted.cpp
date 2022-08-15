class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left =0, right=numbers.size()-1;
        vector<int> out;
        while(left<right){
            if((numbers[left] + numbers[right])>target ) right--;
            else if((numbers[left] + numbers[right])<target) left++;
            else {
                out.push_back(left+1);
                out.push_back(right+1);
                return out;
            }
        }
        return out;
        
    }
};