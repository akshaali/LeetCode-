class Solution {
public:
     void merge(vector<int>& arr, int start, int mid, int end)
    {
        vector<int> temp;
        int left = start;
        int right = mid+1;
    
        while (left <=mid && right <= end)
        {
            if (arr[left] > arr[right])
            {
                temp.push_back(arr[right++]);
            }
            else
            {
                temp.push_back(arr[left++]);
            }
        }
        while (left <= mid)
        {
            temp.push_back(arr[left++]);
        }
        while (right <= end)
        {
            temp.push_back(arr[right++]);
        }
        for(int i = start; i<=end; i++){
            arr[i] = temp[i-start];
        }
    }
    
    void mergeSort(vector<int>& arr, int start, int end)
    {
        // base condition
        if (start >= end)
            return;
        
        int mid = start + (end - start) / 2;

        mergeSort(arr, start, mid);
        mergeSort(arr, mid + 1, end);
        merge(arr, start, mid, end);
    }
    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
        mergeSort(nums, 0, n-1);
        return nums;
    }
};