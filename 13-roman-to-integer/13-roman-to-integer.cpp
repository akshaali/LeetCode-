#include <iostream>
using namespace std;

class Solution {
public:
    int char_to_int(char c){
   switch (c){
    case 'I': return 1;
    case 'V': return 5;
    case 'X': return 10;
    case 'L': return 50;
    case 'C': return 100;
    case 'D': return 500;
    case 'M': return 1000;
    default: return -1;
}
    }
    int romanToInt(string s) {
        int num = char_to_int(s[0]);
        cout << num;
        int prev, curr;
        for(int i = 1; i <s.length(); ++i){
            prev = char_to_int(s[i-1]);
            curr = char_to_int(s[i]);
            if(curr <= prev){
                num = num + curr;
            }else{
                num = num + curr - 2*prev;
            }
        }
        
        return num;
    }
};