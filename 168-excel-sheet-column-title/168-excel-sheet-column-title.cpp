using namespace std;
class Solution {
public:
    string convertToTitle(int columnNumber) {
       string res;
        while(columnNumber>0){
            columnNumber--;
            int curr = columnNumber % 26;
            columnNumber /= 26;
            res += (curr + 'A');
        }
        reverse(res.begin(), res.end());
        return res;
    }
};