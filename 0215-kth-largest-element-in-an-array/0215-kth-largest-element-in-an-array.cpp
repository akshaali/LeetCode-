class Solution {
    //priority ques
// public:
//     int findKthLargest(vector<int>& nums, int k) {
//         priority_queue<int, vector<int>, greater<int>> pq;
//         int ans = INT_MIN;
//         for(auto n: nums){
//             pq.push(n);
//             if(pq.size()>k) pq.pop();
//         }
//         return pq.top();
//     }
    public:
    int findKthLargest(vector<int>nums, int k) {
      return quickSelect(nums, 0, nums.size() - 1, k);
    }

int quickSelect(vector<int> nums, int low, int high, int k) {
  int pivot = low;

  // use quick sort's idea
  // put nums that are <= pivot to the left
  // put nums that are  > pivot to the right
  for (int j = low; j < high; j++) {
    if (nums[j] <= nums[high]) {
      swap(nums[pivot++], nums[j]);
    }
  }
  swap(nums[pivot], nums[high]);
  
  // count the nums that are > pivot from high
  int count = high - pivot + 1;
  // pivot is the one!
  if (count == k) return nums[pivot];
  // pivot is too small, so it must be on the right
  if (count > k) return quickSelect(nums, pivot + 1, high, k);
  // pivot is too big, so it must be on the left
  return quickSelect(nums, low, pivot - 1, k - count);
}
};


