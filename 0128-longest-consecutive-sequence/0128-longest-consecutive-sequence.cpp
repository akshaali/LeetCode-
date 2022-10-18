class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> mp;
        int max_sequence_length = 0;
        for(auto num : nums){
            if(mp[num]){
                continue;
            }
            mp[num] = 1;
        }
        for(auto num: nums){
            int curr_num = num;
            int curr_sequence_len = 1;
            if(!mp[curr_num-1]){
                while(mp[curr_num + 1]){
                    curr_num +=1;
                    curr_sequence_len +=1;
                }
                max_sequence_length = max(max_sequence_length, curr_sequence_len);
            }
        }
        return max_sequence_length;
    }
};