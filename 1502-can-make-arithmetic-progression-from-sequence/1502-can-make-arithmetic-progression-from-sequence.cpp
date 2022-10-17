class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int n = arr.size();
        if(n==1) return true;
        int diff = (arr[n-1] - arr[0]) /(n-1);
        for(int i = 1; i<n; i++){
            if((arr[i] -arr[i-1]) != diff){
                return false;
            }
        }
        return true;
    }
};