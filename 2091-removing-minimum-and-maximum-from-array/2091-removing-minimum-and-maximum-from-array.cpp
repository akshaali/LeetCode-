using namespace std;
class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int minIndx = 0, maxIndx = 0;
        int n = nums.size();
        for(int i = 0; i< nums.size(); i++){
            if(nums[i]<nums[minIndx]){
                minIndx = i;
            }
            if(nums[i]>nums[maxIndx]){
                maxIndx = i;
            }
        }
        // cout<<minIndx<<" "<<maxIndx<<endl;
        //both front 
        int dele1 = maxIndx>=minIndx ? maxIndx+1 : minIndx+1;
        //both back
        int dele2 = maxIndx>=minIndx ? n - minIndx : n - maxIndx;
        //front and back
        int dele3 =  maxIndx>=minIndx ? minIndx + 1 + n - maxIndx :  maxIndx + 1 + n - minIndx;
        // cout<<dele1<<" "<<dele2<<" "<<dele3;
        if(dele1<=dele2 && dele1<= dele3) return dele1;
        else if(dele2<=dele1 && dele2<=dele3) return dele2;
        return dele3;
        
    }
};