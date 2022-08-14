class Solution {
public:
    int mySqrt(int x) {
        int start = 0;
        int end = x;
        long int mid;
        if(x == 0 )return 0;
        else if(x ==1) return 1;
        while(start <= end){
          mid = (start+end)/2;
          if(x<=mid*mid && x>=(mid-1)*(mid-1)){
              if(x == mid*mid)return mid;
              else return mid-1;
          }else if(mid*mid > x){
              end = mid -1;
          }else{
              start = mid+1;
          }
        }
        return mid;
        
    }
};