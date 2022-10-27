using namespace std;

class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        if(nums.size() <2) return 0;
        
        unordered_map<int, int>even_hash_map;
        unordered_map<int, int>odd_hash_map;
        int total_even = 0, total_odd = 0;
        for(int i = 0; i<nums.size(); i++){
            if(i&1){
                odd_hash_map[nums[i]]++;
                total_odd++;
            }else{
                even_hash_map[nums[i]]++;
                total_even++;
            }
        }
        
        int first_even_count = 0, first_even_num = 0;
        int second_even_count = 0, second_even_num = 0;
        for(auto item: even_hash_map){
            int num = item.first;
            int count = item.second;
            if(count > first_even_count){
                second_even_count = first_even_count;
                first_even_count = count;
                second_even_num = first_even_num;
                first_even_num = num;
            }else if (count>second_even_count){
                second_even_count= count;
                second_even_num = num;
            }
        }
        
        // cout<<"first_even_count "<<first_even_count<<" first_even_num "<<first_even_num<<endl;
        // cout<<"second_even_count "<<second_even_count<<" second_even_num "<<second_even_num<<endl;

        
        int first_odd_count = 0, first_odd_num = 0;
        int second_odd_count = 0, second_odd_num = 0;
        for(auto item: odd_hash_map){
            int num = item.first;
            int count = item.second;
            if(count > first_odd_count){
                second_odd_count = first_odd_count;
                first_odd_count = count;
                second_odd_num = first_odd_num;
                first_odd_num = num;
            }else if (count>second_odd_count){
                second_odd_count= count;
                second_odd_num = num;
            }
        }
        
        // cout<<"first_odd_count "<<first_odd_count<<" first_odd_num "<<first_odd_num<<endl;
        // cout<<"second_odd_count "<<second_odd_count<<" second_odd_num "<<second_odd_num<<endl;
        
        
        int even_operation = total_even - first_even_count;
        int odd_operation = total_odd - first_odd_count;
        
        if(first_even_num!=first_odd_num) even_operation +=(total_odd - first_odd_count);
        else even_operation += (total_odd - second_odd_count);
        
        if(first_odd_num!=first_even_num) odd_operation +=(total_even - first_even_count);
        else odd_operation +=(total_even - second_even_count);
        
        return min(even_operation, odd_operation);
    }
};