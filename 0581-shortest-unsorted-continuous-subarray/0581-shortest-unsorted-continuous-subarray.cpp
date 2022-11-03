using namespace std;
class Solution {
public:
    int findUnsortedSubarray(vector<int>& A) {
        int n = A.size(), beg = -1, end = -2, mini = A[n-1], maxi = A[0];
        for (int i=1;i<n;i++) {
          maxi = max(maxi, A[i]);
          mini = min(mini, A[n-1-i]);
          if (A[i] < maxi) end = i;
          if (A[n-1-i] > mini) beg = n-1-i; 
        // cout<<maxi<<" "<<mini<<" "<<beg<<" "<<end<<endl;
        }
        return end - beg + 1;
    }
};