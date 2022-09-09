using namespace std;
class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> answer;
        // int i, j;
        // int count[101] = {0, 0, 0};
		int len = nums.size();
//         for(i = 0; i < len; i++) {
//             count[nums[i]]++;
//         }
//         for(i = 1; i < 101; i++) {
//             count[i] += count[i - 1];
//         }
//         for(i = 0; i < len; i++) {
//             if(nums[i] == 0)
//                 answer.push_back(0);
//             else
//                 answer.push_back(count[nums[i] - 1]);
                
//         }
//         return answer;
         map<int, int> mp;
        for(int i = 0; i < len; i++) {
            mp[nums[i]] = mp[nums[i]] + 1;
        }
        for (int i =1; i<mp.size(); i++)
    {
         mp[i] += mp[i-1];
        cout <<i<<" "<< mp[i] <<endl;
    }
                for(int i = 0; i < len; i++) {
            if(nums[i] == 0)
                answer.push_back(0);
            else
                answer.push_back(mp[nums[i] - 1]);
                
        }
        return answer;
        
    }
};