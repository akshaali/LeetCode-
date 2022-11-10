class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        vector<int> ans;
        sort(nums.begin(), nums.end());
        for(int i = 1; i< nums.size(); i++){
            nums[i] += nums[i-1];
        }
        for(int i = 0; i<queries.size(); i++){
            ans.push_back(binarySearch(nums, queries[i]));
        }
        return ans;
    }
    int binarySearch(vector<int> nums, int value){
        int start = 0, end = nums.size();
        while(start<end){
            int mid = start + (end - start)/2;
            if(nums[mid]>value) end = mid;
            else start = mid+1;
        }
        return start;
    }
};