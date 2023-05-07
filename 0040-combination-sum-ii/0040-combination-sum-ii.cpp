class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        int size = candidates.size();
        vector<vector<int>> output;
        vector<int> subset;
        targetSum(0, 0,output, subset, size, candidates, target);
        return output;
        
    }
    void targetSum(int index, int sum, vector<vector<int>> &output, vector<int> subset, int size, vector<int> &candidates, int target){
        if(index >= size || sum >=target){
            if(sum == target){
                output.push_back(subset);
            }
            return;
        }
        for(int i = index ; i<size; i++){
            if(i>index && candidates[i-1] == candidates[i] ) continue;
            sum += candidates[i];
            subset.push_back(candidates[i]);
            targetSum(i+1, sum, output, subset, size,candidates, target);
            sum -= candidates[i];
            subset.pop_back();
        }
    }
    
};