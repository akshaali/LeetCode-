using namespace std;
class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int maxIndexM = 0, maxIndexP = 0, maxIndexG = 0;
        int time = 0;
        for(int i =0; i< garbage.size(); i++){
             bool flagM = false, flagP = false, flagG = false;
            for(auto i: garbage[i]){
                time +=1;
                if(i == 'M'){
                    flagM = true;
                }else if(i == 'P'){
                    flagP = true;
                }else{
                    flagG = true;
                }
            }
            cout<<garbage[i]<<" "<<flagM<<" "<<flagP<<" "<<flagG<<endl;
            if(flagM) maxIndexM =i;
            if(flagP) maxIndexP =i;
            if(flagG) maxIndexG =i;
        }
        for(int i = 1; i<travel.size(); i++){
            travel[i] += travel[i-1];
        }
        cout<<"maxIndexM: "<<maxIndexM<<" maxIndexP: "<<maxIndexP<<" maxIndexG: "<<maxIndexG<<endl;
        time += maxIndexM>0 ? travel[maxIndexM -1] : 0;
        time += maxIndexP>0 ? travel[maxIndexP -1] : 0;
        time += maxIndexG>0 ? travel[maxIndexG -1] : 0;
        return time;
        
    }
};