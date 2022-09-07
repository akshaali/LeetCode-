class Solution {
public:
    int minPartitions(string n) {
        int maxDigit = 0;
        for(int i = 0; i< n.size(); i++){
            int curr = n[i] - '0';
            if(maxDigit < curr){
                maxDigit = curr;
            }
        }
        return maxDigit;
        
    }
};