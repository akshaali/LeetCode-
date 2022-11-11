using namespace std;
class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        double waitingTime = 0;
        int n = customers.size();
        int time = customers[0][0];
        for(int i = 0; i<n; i++){
            waitingTime += customers[i][0]>time ? customers[i][1] : time - customers[i][0] + customers[i][1];
            time = customers[1][0] > time ? customers[i][0] + customers[i][1] : time+ customers[i][1]; 
            // cout<<time<<" "<<waitingTime<<endl;
        }
        return waitingTime/n;
    }
};