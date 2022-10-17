class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
//         vector<bool> ans;
//         for(int i = 0; i< l.size(); i++){
//             auto start = nums.begin() + l[i];
//             auto end = nums.begin() + r[i] + 1;

//             // To store the sliced vector
//             vector<int> result(l[i] - r[i] + 1);

//             // Copy vector using copy function()
//             copy(start, end, result.begin());
//             ans.push_back(checkIsAP(result));
//         }
//         return ans;
        vector<bool> res;
        for (auto i = 0, j = 0; i < l.size(); ++i) {
            vector<int> n(begin(nums) + l[i], begin(nums) + r[i] + 1);
            sort(begin(n), end(n));
            for (j = 2; j < n.size(); ++j)
                if (n[j] - n[j - 1] != n[1] - n[0])
                    break;
            res.push_back(j == n.size());
        }
        return res;
        
    }
    bool checkIsAP(vector<int>& arr){
          int n = arr.size();
          if (n == 1)
            return true;

          // Sort array
          sort(arr.begin(), arr.end());

          // After sorting, difference between
          // consecutive elements must be same.
          int d = arr[1] - arr[0];
          for (int k=2; k<n; k++)
            if (arr[k] - arr[k-1] != d)
              return false;
          return true;
    }
};