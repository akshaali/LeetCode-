using namespace std;
class Solution {
public:
    vector<int> decompressRLElist(vector<int>& nums) {
        vector<int>res;
        for(int i = 0; i<nums.size(); i += 2){
            int num = nums[i];
            cout<<"num has arrived: "<<num<<"values of i: "<< i<<endl;
            // for(int j = 0; j<num; j++){
            //      cout<<num<<endl;
            // }
            while(num>0){
                cout<<num<<endl;
                res.push_back(nums[i+1]);
                num = num - 1;
            }
        }
        return res;
        
        
    }
};