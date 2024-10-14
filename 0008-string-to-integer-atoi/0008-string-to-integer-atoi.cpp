class Solution {
public:
    int helper(string str, int i, int base, int sign){
        if(i>= str.size()) return base*sign;
        if(!(isdigit(str[i]))){
            return (base*sign);
        }
        if (base >  INT_MAX / 10 || (base == INT_MAX / 10 && str[i] - '0' > 7)) {
                if (sign == 1) return INT_MAX;
                else return INT_MIN;
        }
       base = 10*base + (str[i]-'0');
        return helper(str, i+1, base, sign);
        
    }
    int myAtoi(string str, int i = 0, int base = 0, int sign = 1) {
        while(str[i] == ' ') i++;
        if (str[i] == '-' || str[i] == '+') {
            sign = 1 - 2 * (str[i++] == '-');
        }
        cout<<sign<<endl;
        return helper(str, i, base, sign);
    }
};