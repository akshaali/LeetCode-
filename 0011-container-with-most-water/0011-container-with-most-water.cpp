class Solution {
public:
    int maxArea(vector<int>& height) {
        int p1 = 0;
        int p2 = height.size()-1;
        int ans = 0;
        while(p1<p2){
            int len = p2-p1;
            int bredth = min(height[p1],height[p2]);
            int currArea = len*bredth;
            ans = max(ans, currArea);
            if(height[p1]<height[p2])p1++;
            else p2--;
        }
        return ans;
    }
};