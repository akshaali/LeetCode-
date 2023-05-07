class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> output;
        vector<int> subset;
        helper(1, n, k, 0, output, subset);
        return output;
    }
    void helper(int index, int n, int k, int sum, vector<vector<int>> &output, vector<int> subset){
        if(index>9 || sum>=n || subset.size() >=k ){
            if(sum ==n && subset.size() == k){
                output.push_back(subset);
            }
            return;
        }
        subset.push_back(index);
        sum += index;
        helper(index+1,n,k,sum,output,subset);
        sum -=index;
        subset.pop_back();
        helper(index+1,n,k,sum,output,subset);
    }
};