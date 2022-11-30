class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int maxLeft = height[0] , maxRight = height[n-1];
        int left = 0, right = n -1;
        int ans = 0;
       while(left<right){
            if(maxLeft<=maxRight){
                ans += (maxLeft - height[left]>0 ? maxLeft - height[left] : 0 );
                left++;
                maxLeft = max(maxLeft, height[left]);
            }else{
                ans += (maxRight - height[right]>0 ? maxRight - height[right] : 0 );
                right--;
                maxRight = max(maxRight, height[right]);
            }
        }
        return ans;
    }
};