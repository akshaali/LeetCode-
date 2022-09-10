class Solution {
public:
    int minMoves(int target, int maxDoubles) {
        long long int moves = 0;
        while(target>1){
            if(target%2 == 0 && maxDoubles>0){
                target /=2;
                maxDoubles--;
                moves++;
            }else if(maxDoubles>0){
                target -=1;
                moves++;
            }else{
                moves += (target - 1);
                target = 1;
            }
        }
        return moves;
    }
};