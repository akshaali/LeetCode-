class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> output;
        vector<int> subset;
        createSubset(1, output, subset, n, k);
        return output;
        
    }
    void createSubset(int index, vector<vector<int>> &output, vector<int>subset,
                     int n, int k){
        if(index > n || subset.size() == k){
           if(subset.size() == k){
                output.push_back(subset);
           }
            return;
        }
        // subset.push_back(index);
        // createSubset(index+1, output, subset, n, k);
        // subset.pop_back();
        // createSubset(index+1, output, subset, n, k);
        for(int i=index;i<n+1;i++)
        {
            subset.push_back(i);  //consider the current element i
            createSubset(i+1,output,subset,n, k); // generate combinations
            subset.pop_back(); //proceed to next element
        }
    }
};