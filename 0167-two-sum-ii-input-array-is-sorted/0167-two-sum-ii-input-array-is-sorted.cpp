class Solution {
public:
    int binarySearch(vector<int>& numbers, int index, int target){
        int start = 0;
        int end = numbers.size()-1;
        while(start<=end){
            int mid = start + (end-start)/2;
            if(numbers[mid] == target && mid != index) return mid;
            else if(numbers[mid]>target) end = mid-1;
            else start = mid+1;
        }
        return -1;
    }
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int>ans;
        int n = numbers.size();
        for(int i = 0; i<n; i++){
            int num = numbers[i];
            int found = binarySearch(numbers, i, target-num);
            if(found != -1) {
                ans.push_back(i+1);
                ans.push_back(found+1);
                return ans;
            }
        }
        return ans;
    }
};