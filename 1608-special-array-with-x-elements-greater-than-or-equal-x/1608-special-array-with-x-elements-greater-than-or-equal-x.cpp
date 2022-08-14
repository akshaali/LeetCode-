using namespace std;
class Solution {
public:
    int specialArray(vector<int>& nums) {
      sort(nums.begin(), nums.end());
      int start = 0;
      int end = nums.size();
        while (start <= end) {
            int mid = start + (end - start) /2;
            int count = find(nums,mid);
            if (mid == count) {
                return mid;
            }
            if (count > mid) {
                start = mid + 1;
            }
            else {
                end = mid - 1;
            }
        }
        return -1;

    }
    int find(vector<int> &nums , int mid) {
        int count = 0;
        for(auto element:nums) {
            if (element>=mid) {
                count++;
            }
        }
        return count; 
    }
};