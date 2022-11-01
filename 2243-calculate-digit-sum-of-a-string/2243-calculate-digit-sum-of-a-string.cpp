using namespace std;
class Solution {
public:
    string digitSum(string s, int k) {
       if(s.size() <= k)
            return s;
        string r = "";
        for(int i = 1, sum = 0; i <= s.size(); i++){
            sum += s[i - 1] - '0';
            if(i % k == 0 || i == s.size()){
                // cout<<sum<<endl;
                r += (to_string(sum));
                sum = 0;
            }
        }
        return digitSum(r, k);
    }
};