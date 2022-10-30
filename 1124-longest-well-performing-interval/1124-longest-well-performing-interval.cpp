using namespace std;
class Solution {
public:
    int longestWPI(vector<int>& hours) {
        int ans = 0, hour = 0;
        unordered_map<int, int> seen;
        for(int i = 0; i< hours.size(); i++){
            hour += hours[i] > 8 ? 1 : -1;
            if(hour>0) ans = i+1;
            else{
                if(seen.find(hour) == seen.end()){
                    seen[hour] = i;
                }
                if(seen.find(hour-1) != seen.end()){
                    ans = max(ans, i - seen[hour-1]);
                    // cout<<"here it comes "<<ans<<endl;
                }
            }
        }
        return ans;
    }
};