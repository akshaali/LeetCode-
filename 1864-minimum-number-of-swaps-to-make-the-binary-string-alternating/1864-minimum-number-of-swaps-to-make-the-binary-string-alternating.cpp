class Solution {
public:
    int minSwaps(string s) {
        int n = s.size();
        int count0 = 0;
        int count1 = 0;
        for(int i = 0; i<n; i++){
            if(s[i] == '0') count0++;
        }
        count1 = n - count0;
        if(abs(count0-count1)>1) return -1;
        int miss0 = 0, miss1 = 0;
        for (int i = 0; i < n; i += 2) {
            miss0 += s[i] != '0';
            miss1 += s[i] != '1';
        }
        return count0 == count1 ? min(miss0, miss1) : count0 > count1 ? miss0 : miss1;   
    }
};