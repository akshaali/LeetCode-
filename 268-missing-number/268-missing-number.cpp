using namespace std;
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        long long int sum = 0;
        int size = nums.size();
         long long int Totalsum = size*(size+1)/2;
        for(auto ele: nums){
            sum +=ele;
        }
        
        cout<<Totalsum<<"   "<<sum;
        return (Totalsum - sum);
        
    }
};