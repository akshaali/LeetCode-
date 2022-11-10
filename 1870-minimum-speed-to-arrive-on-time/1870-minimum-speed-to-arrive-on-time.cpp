using namespace std;
class Solution {
public:
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int n = dist.size();
        if(ceil(hour)<n) return -1;
        int low = 1, high = 1e7;
        while(low<high){
            int mid = low + (high-low)/2;
            // cout<<"low: "<<low<<" high: "<<high<<" mid: "<<mid<<endl;
            if(valid(dist, mid, hour)) high = mid;
            else low = mid+1;
        }
        return low;
    }
    bool valid(vector<int> dist, int s, double hour){
        double time = 0;
        for(auto d: dist){
            time = ceil(time);
            time +=  (double)d / s;
            // cout<<"time: "<< time<<endl;
            if(time>hour) return false;
        }
        return true;
    }
};