class Solution {
public:
    int splitNum(int num) {
            int cnt[10] = {}, n1 = 0, n2 = 0, first = true;
    for(; num; num /= 10)
        ++cnt[num % 10];
    for (int i = 0; i < 10; i += cnt[i] == 0) {
        if (cnt[i]) {
            --cnt[i];
            n1 = first ? n1 * 10 + i : n1;
            n2 = !first ? n2 * 10 + i : n2;
            first = !first;
        }
    }
    return n1 + n2;
        
    }
};