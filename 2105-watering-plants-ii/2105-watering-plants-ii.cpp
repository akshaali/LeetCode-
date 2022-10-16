class Solution {
public:
    int minimumRefill(vector<int>& plants, int capacityA, int capacityB) {
        int start = 0, end = plants.size()-1;
        int currCapA = capacityA, currCapB = capacityB;
        int refil = 0;
        while(end>start){
            if(currCapA<plants[start]){
                refil++;
                currCapA = capacityA - plants[start];
            }else{
                currCapA -= plants[start];
            }
            if(currCapB<plants[end]){
                refil++;
                currCapB = capacityB - plants[end];
            }else{
                currCapB -=plants[end];
            }
            start++;
            end--;
        }
        if(end == start){
            if(currCapA == currCapB && currCapA<plants[start]) refil++;
            else if(currCapA>currCapB && currCapA<plants[start]) refil++;
            else if(currCapB>currCapA && currCapB<plants[start]) refil++;
        }
        return refil;   
    }
};