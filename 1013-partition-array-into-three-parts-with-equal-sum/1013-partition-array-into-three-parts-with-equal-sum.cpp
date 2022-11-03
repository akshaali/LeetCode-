class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& arr) {
        auto total = accumulate(begin(arr), end(arr), 0);
        int parts = 0;
          if (total % 3 != 0) return false;
          for (auto i = 0, sum = 0; i < arr.size(); ++i) {
            sum += arr[i];
            if (sum == (parts + 1) * total / 3) ++parts;
          }
          return parts >= 3;
    }
};