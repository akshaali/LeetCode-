using namespace std;
class Solution {
public:
    int firstUniqChar(string s) {
        int arr[26] = {0};
        queue<int> que;
        int ans = -1;
        for(int i = 0; i<s.length(); i++){
            arr[s[i]-97]++;
            que.push(i);
        }
        while(!que.empty()){
            int index = que.front();
            if(arr[s[index]-97]==1) return index;
            que.pop();
        }
        return ans;
    }
};