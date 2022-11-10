using namespace std;
class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        vector<int> res;
        int n(size(potions));
        sort(begin(potions), end(potions));
        
        for (auto& spell : spells) {
            int start(0), end(n);
            while (start < end) {
                int mid = start + (end-start)/2;
                ((long long)spell*potions[mid] >= success) ? end = mid : start = mid+1;
            }
            res.push_back(n-start);
        }
        return res;
        // vector<int> ans;
        // sort(potions.begin(), potions.end());
        // for(int i = 0; i< spells.size(); i++){
        //     int need = success/spells[i] + (success%spells[i] !=0);
        //     ans.push_back(binarySearch(potions, need));
        // }
        // return ans;
    }
    int binarySearch(vector<int> pot, int need){
        int start = 0, end = pot.size() -1;
        // cout<<"need: "<<need<<endl;
        if(pot[end]<need) return 0;
        while(start<end){
            int mid = start + (end - start)/2;
            // cout<<"start: "<<start<<" end: "<<end<<" mid: "<<mid<<endl;
            if(pot[mid] >= need) end = mid;
            else start = mid+1;
        }
        return pot.size() - start;
    }
};