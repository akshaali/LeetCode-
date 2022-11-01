using namespace std;
class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        vector<int> remainder(k, 0);
        for(auto n: arr) remainder[(n%k + k)%k]++;
        if(remainder[0]&1) return false;
        for(int i = 1; i<k; i++){
            if(remainder[i] != remainder[k-i]) return false;
        }
        return true;
        
    }
};