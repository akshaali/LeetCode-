//TC: O(n) SC: O(1)
class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        int peak = 1;
        int currCandy = 1;
        int ans = 1;
        int i = 1;
        while(i<n){
            //constant
            while(i<n && ratings[i]==ratings[i-1]){
                currCandy = 1;
                ans++;
                i++;
            }
            //increasing slope
            currCandy = 1;
            peak = 1;
            while(i<n && ratings[i]>ratings[i-1]){
                currCandy++;
                ans += currCandy;
                i++;
            }
            peak = currCandy;
            currCandy = 0;
            //decreasing slope
            while(i<n && ratings[i]<ratings[i-1]){
                currCandy++;
                ans += currCandy;
                i++;
            }
            ans = ans + max(peak, currCandy+1) - peak;
        }
        return ans;
    }
};