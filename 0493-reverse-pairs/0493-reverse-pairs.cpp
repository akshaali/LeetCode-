class Solution {
public:
    void printArr(vector<int> arr){
        cout<<"[";
        for(auto a: arr) cout<<a<<", ";
        cout<<"]"<<endl;
    }
void merge(vector<int> &arr, int start, int mid, int end)
    {
        vector<int> temp;
        int left = start;
        int right = mid+1;
        int arrIndex = start;
    
        while (left <=mid && right <= end)
        {
            if (arr[left] <= arr[right])
            {
                temp.push_back(arr[left++]);
            }
            else
            {
                temp.push_back(arr[right++]);
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
    
 int mergeSort(vector<int> &arr, int start, int end)
    {
         int count = 0;
        // base condition
        if (start >= end)
            return count;
    
        int mid = start + (end - start) / 2;
        // cout<<start<<" "<<mid<<" "<<end<<endl;
        count += mergeSort(arr, start, mid);
        count += mergeSort(arr, mid + 1, end);
        // cout<<start<<" === "<<mid<<" === "<<end<<endl;
        // printArr(arr);
        for(int i = start, j = mid+1; i<=mid; i++){
            while(j<=end && arr[i]/2.0>arr[j]) j++;
            count += j - (mid+1);
        }
        merge(arr, start, mid, end);
        return count;
    }
    int reversePairs(vector<int>& nums) {
        int ans = 0;
        int n = nums.size();
        ans = mergeSort(nums,0, n-1);
        // printArr(nums);
        return ans;
    }
};