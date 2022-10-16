using namespace std;
class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int start = 0, end = nums.size() -1;
        while(start<end){
            cout<<(nums[start]&1)<<"    "<<(nums[end]&1)<<endl;
            if(nums[start]&1 && !(nums[end]&1)){
                cout<<start<<" "<<end<<endl;
                swap(nums[start], nums[end]);
                start++;
                end--;
            }else if(!(nums[start]&1)){
                cout<<"Hey!!!!........    "<<start<<" "<<end<<endl;
                start++;
            }
            else if(nums[end]&1){
                cout<<"Hiiiiiiiiiii!!!!........    "<<start<<" "<<end<<endl;
                end--;
            }
        }
        return nums;
        
    }
};