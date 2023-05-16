using namespace std;
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        if(n1>n2) return findMedianSortedArrays(nums2, nums1);
        double ans = 0;
        int low = 0, high = n1;
        while(low<=high){
            int cut1 = (low+high)/2;
            int cut2 = (n1+n2+1)/2 - cut1;
            // cout<<cut1<<" "<<cut2<<endl;
            
            int left1= cut1 == 0 ? INT_MIN : nums1[cut1-1];
            int left2 = cut2 == 0 ? INT_MIN : nums2[cut2-1];
            
            int right1 = cut1 == n1 ? INT_MAX : nums1[cut1];
            int right2 = cut2 == n2 ? INT_MAX : nums2[cut2];
            
            if(left1<=right2 && left2<=right1){
                if((n1+n2)%2 == 0){
                    ans = (max(left1, left2) + min(right1, right2))/2.0;
                    // cout<<max(left1, left2)<<" "<< min(right1, right2)<<endl;
                }else{
                    ans = max(left1, left2);
                }
                // cout<<ans<<endl;
                return ans;
            }else if(left1>right2){
                high = cut1-1;
                
            }else if(left2>right1){
                low = cut1+1;
            }
            
        }
        return ans;
    }
};