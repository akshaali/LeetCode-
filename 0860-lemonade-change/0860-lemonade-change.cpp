class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int coins5 = 0;
        int coins10 = 0;
        int coins20 = 0;
        int n = bills.size();
        for(int i = 0; i<n; i++){
            int bill = bills[i];
            if(bill == 5){
                coins5++;
            }else if(bill == 10){
                if(coins5 == 0) return false;
                coins10++;
                coins5--;
            }else{
                if(coins10>0 && coins5>0){
                    coins10--;
                    coins5--;
                }else if(coins5>=3){
                    coins5 -= 3;
                }else{
                    return false;
                }
                coins20++;
            }
        }
        return true;
    }
};