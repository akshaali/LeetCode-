using namespace std;
class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        int n = nums.size();
        if(n%k) return false;
        map<int, int> freq;
        map<int,int>::iterator it;
        for(auto n: nums) freq[n]++;
        for(it=freq.begin();it!=freq.end();it++){
            int frequency = it->second;
            if(frequency){
                for(int i = 0; i<k; i++){
                if(freq[it->first+i] < frequency) return false;
                else {
                    freq[it->first+i] -= frequency;
                }
            }
        }
            
        }
        return true;
    }
};