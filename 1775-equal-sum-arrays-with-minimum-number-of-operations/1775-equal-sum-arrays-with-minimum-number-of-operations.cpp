using namespace std;
class Solution {
public:
    int minOperations(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size() * 6 < nums2.size() || nums2.size() * 6 < nums1.size())
            return -1;
    int sum1 = accumulate(begin(nums1), end(nums1), 0);
    int sum2 = accumulate(begin(nums2), end(nums2), 0);
    // cout<<sum1<<" "<<sum2<<endl;
    if (sum1 > sum2)
        swap(nums1, nums2);
    int sumn1 = accumulate(begin(nums1), end(nums1), 0);
    int sumn2 = accumulate(begin(nums2), end(nums2), 0);
    // cout<<sumn1<<" "<<sumn2<<endl;
    priority_queue<int, vector<int>, greater<int>> pq1(nums1.begin(), nums1.end());
    priority_queue<int> pq2(nums2.begin(), nums2.end());
    int diff = abs(sum2 - sum1);
    int ans = 0;
    while(diff>0){
        // cout<<pq2.top()<<" "<<pq1.top()<<endl;
        ans++;
        if( pq2.empty() || (!pq1.empty() && 6-pq1.top()>pq2.top()-1)){
            diff -= 6-pq1.top();
            // cout<<"come here??? "<<diff<<endl;
            pq1.pop();
        }else{
            diff -= pq2.top()-1;
            // cout<<"else here?? "<<diff<<endl;
            pq2.pop();
        }
    }
    return ans;
    }
};