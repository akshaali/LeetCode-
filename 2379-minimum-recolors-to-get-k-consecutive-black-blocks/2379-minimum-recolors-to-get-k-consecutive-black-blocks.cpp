class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int whiteCount = INT_MAX;
        int front = 0, back = 0;
        int currWhiteCount = 0;
        while(front<blocks.size()){
            if(blocks[front] == 'W') currWhiteCount++;
            if(front - back +1 == k){
                whiteCount = min(whiteCount,currWhiteCount);
                if(blocks[back] == 'W') currWhiteCount--;
                back++;
            }
            front++;
        }
        return whiteCount;
    }
};