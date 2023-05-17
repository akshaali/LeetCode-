//similar to count inversion
using namespace std;
class Solution {
public:
    void merge(vector<pair<int, int>>& numsWithOriginalIndx, int start, int mid, int end, vector<int> & ans)
    {
        vector<pair<int,int>> temp;
        int left = start;
        int right = mid+1;
        // cout<<left<<" "<<mid<<" "<<right<<endl;
        int rightLessThanLeft = 0;
    
        while (left <=mid && right <= end)
        {
            if (numsWithOriginalIndx[left].first > numsWithOriginalIndx[right].first)
            {
                temp.push_back(numsWithOriginalIndx[right++]);
                rightLessThanLeft++;
            }
            else
            {
                ans[numsWithOriginalIndx[left].second] += rightLessThanLeft;
                temp.push_back(numsWithOriginalIndx[left++]);
            }
        }
        // cout<<"rightLessThanLeft "<<rightLessThanLeft<<endl;
        while (left <= mid)
        {
            ans[numsWithOriginalIndx[left].second] += rightLessThanLeft;
            temp.push_back(numsWithOriginalIndx[left++]);
        }
        while (right <= end)
        {
            temp.push_back(numsWithOriginalIndx[right++]);
        }
        for(int i = start; i<=end; i++){
            numsWithOriginalIndx[i] = temp[i-start];
        }
    }
    
    void mergeSort(vector<pair<int, int>>& numsWithOriginalIndx, int start, int end, vector<int> & ans)
    {
        // base condition
        if (start >= end)
            return;
    
        int mid = start + (end - start) / 2;
    
        mergeSort(numsWithOriginalIndx, start, mid, ans);
        mergeSort(numsWithOriginalIndx, mid + 1, end, ans);
        merge(numsWithOriginalIndx, start, mid, end, ans);
    }
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, 0);
        vector<pair<int,int>> numsWithOriginalIndx;
        for(int i = 0; i<n; i++){
            numsWithOriginalIndx.push_back(make_pair(nums[i], i));
        }
        mergeSort(numsWithOriginalIndx, 0, n-1, ans);
        for(auto num:numsWithOriginalIndx ){
            cout<<num.first<<" ";
        }
        return ans;
    }
};