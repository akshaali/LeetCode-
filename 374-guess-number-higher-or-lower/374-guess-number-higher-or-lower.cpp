/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        int start = 0;
        int end = n;
       int mid;
        while(start<=end){
            mid = start+(end - start)/2; 
            int pick = guess(mid);
            if(pick == 0) return mid;
            else if(pick == 1){
                start = mid+1;
            }else {
                end = mid -1;
            }
        }
        return mid;
        
        
    }
};