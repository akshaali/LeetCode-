class Solution {
public:
    bool search(vector<string>& nums, string str){
        bool found = false;
        for(auto st: nums){
            if(st == str) return true;
        }
        return found;
    }
    string helper(int i, int n, string str, vector<string>& nums){
        if(i == n){
            if(!search(nums, str)){
                return str;
            }else return "";
        }
        //take 1
        str += "1";
        string str1 = helper(i+1, n, str, nums);
        if(str1.size()) return str1;
        //take 0
        str.pop_back();
        str += "0";
        string str2 = helper(i+1, n, str, nums);
        if(str2.size()) return str2;
        return "";
        
    }
    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums.size();
        return helper(0, n, "", nums);
        
    }
};