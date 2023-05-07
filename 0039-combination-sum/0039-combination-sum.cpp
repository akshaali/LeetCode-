class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int size = candidates.size();
        vector<vector<int>> output;
        vector<int> subset;
        targetSum(0, 0,output, subset, size, candidates, target);
        return output;
        
    }
    void targetSum(int index, int sum, vector<vector<int>> &output, vector<int> subset, int size, vector<int> &candidates, int target){
        if(index == size || sum >=target){
            if(sum == target){
                output.push_back(subset);
            }
            return;
        }
        if(sum<target){
            sum += candidates[index];
            subset.push_back(candidates[index]);
            targetSum(index, sum, output, subset, size,candidates, target);
            sum -= candidates[index];
            subset.pop_back();
        }
       
        targetSum(index+1, sum, output, subset, size,candidates, target);
    }
    
};