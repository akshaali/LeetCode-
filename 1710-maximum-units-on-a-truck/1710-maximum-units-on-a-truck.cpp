class Solution {
public:
    static bool myfunction(vector<int>& a, vector<int>& b){
        return a[1] > b[1];
    }
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(begin(boxTypes), end(boxTypes),myfunction);
        int ans = 0;
        for(int i = 0; i<boxTypes.size() && truckSize>0; i++){
            int size = min(truckSize, boxTypes[i][0]);
            ans += (boxTypes[i][1]*size);
            truckSize -=size;
        }
        return ans;
    }
};