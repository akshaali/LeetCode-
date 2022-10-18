class Solution {
public:
    long long waysToBuyPensPencils(int total, int cost1, int cost2) {
        long long ways = 0;
        int maxCost = max(cost1, cost2);
        int minCost = min(cost1, cost2);
        int subWays = total/maxCost;
        while(subWays>=0){
            int currTotal = total - (subWays*maxCost);
            ways += (currTotal/minCost) + 1;
            subWays--;
        }
        return ways;
    }
};