using namespace std;
class Solution {
public:
    bool equalFrequency(string word) {
        int freq[26] = {};
        for(auto ch: word) freq[ch-'a']++;
        unordered_map<int, int> freqCount;
        for(int i = 0; i<26; i++){
            if(freq[i]){
                freqCount[freq[i]]++;
            }
        }
        // for(auto i: freqCount) cout<<" i.first: "<<i.first<<", i.second: "<<i.second<<endl;
        
        
        if(freqCount.size() == 1){
            auto it = freqCount.begin();
            if(it->first == 1 || it->second == 1 ) return true;
        }
        if(freqCount.size() == 2){
            int freq1 = 0 , numofEleFreq1 = 0;
            int freq2 = 0, numOfEleFreq2 = 0;
            for(auto item: freqCount){
                if(item.second >numofEleFreq1){
                    numOfEleFreq2 = numofEleFreq1;
                    freq2 = freq1;
                    numofEleFreq1 = item.second;
                    freq1 = item.first;
                }else{
                    numOfEleFreq2 = item.second;
                    freq2 = item.first;
                }
            }
            // cout<<"freq1: "<<freq1<<" numofEleFreq1: "<<numofEleFreq1<<" freq2: "<<freq2<<" numOfEleFreq2: "<<numOfEleFreq2<<endl;
            if(numofEleFreq1>numOfEleFreq2){
                if(numOfEleFreq2 == 1 && ((freq2 -1 == freq1) || freq2 -1 == 0)) return true;
            }else if(numOfEleFreq2>numofEleFreq1){
                if(numofEleFreq1 == 1 && ((freq1 -1 == freq2) || freq1 -1 == 0)) return true;
            }else if(numOfEleFreq2 == numofEleFreq1 && numofEleFreq1 == 1){
                if(abs(freq1-freq2) == 1) return true;
                if(freq1-1 == 0 || freq2 -1 == 0) return true;
            }
        }
        return false;
        
    }
};