class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char, int>> st;
        string res = "";
        for(auto ch: s){
            if(st.empty() || st.top().first != ch ) st.push({ch, 1});
            else if(++st.top().second == k) st.pop();
            
            // if(!ans.empty()){
            //     pair<char, int> topEle = ans.top();
            //     if(topEle.first == ch){
            //         if(topEle.second == k-1){
            //             ans.pop();
            //         }else{
            //             ans.push({ch, topEle.second+1});
            //         }
            //     }else{
            //         ans.push({ch, 1});
            //     }
            // }else{
            //     ans.push({ch, 1});
            // }
        }
        while (!st.empty()) {
        res += string(st.top().second, st.top().first);
        st.pop();
    }
        reverse(res.begin(), res.end());
         return res;
    }
};