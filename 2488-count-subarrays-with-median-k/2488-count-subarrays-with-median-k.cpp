class Solution {
public:
    int countSubarrays(vector<int>& nums, int k) {
        for(int i =0;i<nums.size();i++){  //*** changing array to 0 1 and -1
            if(nums[i]>k)
            {
                nums[i]= 1;
            }
            else if(nums[i]<k){
                nums[i]= -1;
            }
            else{
                nums[i]=0;
            }
        }
                   
        int res = 0;
        int in = -1;
        for(int i =0;i<nums.size();i++){
            if(nums[i]==0){
                in = i;    //*** index of k in array 
                break;
            }
        }
        
        int sum = 0;
        unordered_map<int,int> hm;
        for(int i = in;i>=0;i--){ //*** going left 
            sum += nums[i];
            hm[sum]++;
        }
        sum = 0;
        for(int i = in;i<nums.size();i++){  //*** going right 
            sum += nums[i];
            int f = -1*sum;
            if(hm.count(f)!=0){
                res += (hm[f]);
            }
            f+=1;
             if(hm.count(f)!=0){
                res += (hm[f]);
            }
        }
        
        return res;
    }
};