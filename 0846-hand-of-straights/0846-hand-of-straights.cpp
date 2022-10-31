class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        if(n%groupSize) return false;
        map<int, int> freq;
        map<int,int>::iterator it;
        for(auto n: hand) freq[n]++;
        for(it=freq.begin();it!=freq.end();it++){
            int frequency = it->second;
            if(frequency){
                for(int i = 0; i<groupSize; i++){
                if(freq[it->first+i] < frequency) return false;
                else {
                    freq[it->first+i] -= frequency;
                }
            }
        }
            
        }
        return true;
        
    }
};