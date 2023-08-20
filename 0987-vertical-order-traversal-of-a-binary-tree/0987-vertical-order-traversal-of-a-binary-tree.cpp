using namespace std;
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    map<int, map<int, vector<int>>> m;
    void dfs(TreeNode* r, int x, int y) {
      if (r != nullptr) {
        m[x][y].push_back(r->val);
        dfs(r->left, x - 1, y + 1);
        dfs(r->right, x + 1, y + 1);
      }
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        dfs(root, 0, 0);
          // for (auto itx = m.begin(); itx != m.end(); ++itx) {
          //     res.push_back(vector<int>());
          //     for (auto ity = itx->second.begin(); ity != itx->second.end(); ++ity) {
          //         res.back().insert(end(res.back()), begin(ity->second), end(ity->second));
          //     }
          // }
        vector<vector<int>>ans;
        for(auto it1 : m){
            ans.push_back(vector<int>());
            for(auto it2 : it1.second){
                sort(it2.second.begin(), it2.second.end());
                for(auto i: it2.second){
                     ans.back().push_back(i);
                }
               
            }
        }
        return ans;
    }
};