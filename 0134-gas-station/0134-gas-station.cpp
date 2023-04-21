class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int balance = 0;
        int total = 0;
        int n = gas.size();
        int startIndex = 0;
        for(int i = 0; i<n; i++){
            balance += gas[i]-cost[i];
            total += gas[i]-cost[i];
            if(balance<0){
                startIndex = i+1;
                balance = 0;
            }
        }
        return total>=0?startIndex:-1;
    }
};