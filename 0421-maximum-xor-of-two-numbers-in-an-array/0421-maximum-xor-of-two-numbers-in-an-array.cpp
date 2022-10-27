class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        int max = 0, mask = 0;
        for(int i = 31; i>=0; i--){
            mask |= (1<<i);
            unordered_set <int> numset;
            for(auto n : nums) numset.insert(n&mask);
            int temp = max|(1<<i);
            for(auto prefix : numset){
                if(numset.find(temp ^ prefix) != numset.end()) {
                    max = temp;
                    break;
                }
            }
        }
        return max;
    }
};