class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        vector<int> ans;
        int depth = 0;
        for(int i = 0; i < seq.length(); i++){
            if(seq[i] == '(') depth++;
            ans.push_back(depth%2);
            if(seq[i] == ')') depth--;
        }
        return ans;
        
    }
};