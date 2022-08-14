class Solution {
public:
    bool isPerfectSquare(int num) {
        int start = 0;
        int end = num;
        long int mid;
        if(num ==0) return 0;
        else if(num ==1) return 1;
        else {
            while(start <=end){
                mid = (start+end)/2;
                if(num<=mid*mid && num>=(mid-1)*(mid-1)){
                    if(mid*mid ==num || (mid-1)*(mid-1) == num) return true;
                    else return false;
                }else if(mid*mid > num){
                    end = mid-1;
                }else{
                    start = mid+1;
                }
            }
            return false;
        }
        
    }
};