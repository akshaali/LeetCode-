using namespace std;
class Solution {
public:
    int partitionArray(vector<int>& A, int k) {
        sort(A.begin(), A.end());
        int res = 1, n = A.size(), j = 0;
        for (int i = 1; i < n; ++i) {
            if (A[i] - A[j] > k) {
                res++;
                j = i;
            }
        }
        return res;
    }
};