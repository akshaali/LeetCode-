using namespace std;
class Solution {
public:
    int wateringPlants(vector<int>& plants, int capacity) {
        int steps = 0;
        int cap = capacity;
        for(int i = 0; i<plants.size();i++){
            if(cap>=plants[i]){
                steps += 1;
                cap -= plants[i];
            }else{
                steps += (i*2 + 1);
                cap = capacity - plants[i];
            }
            cout<<"steps: "<<steps<<"   cap: "<<cap<<endl;
        }
        return steps;
    }
};