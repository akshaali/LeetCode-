class Solution {
public:
    string reverseStr(string s, int k) {
        int start =0;
        int n = s.size();
        int end = n < k ? n-1 : k -1;
        while(start < end){
            reverse(s, start, end);
            if(start + 2*k < n-1){
                start += 2*k;
            }else{
                start = n-1;
            }
            if(end + 2*k < n-1){
                end +=2*k;
            }else{
                end = n-1;
            }
        }
        return s;  
    }
    void reverse(string &s, int start, int end){
         while(start < end){
            swap(s[start], s[end]);
            start++;
            end--;
        }
    }
};