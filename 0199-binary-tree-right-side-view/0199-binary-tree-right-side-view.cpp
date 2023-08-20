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
    void dfs(TreeNode *root, int row, map<int, int>& mp) {
        if (root != nullptr) {
            mp[row] = root->val;
            dfs(root->left, row + 1, mp);
            dfs(root->right, row + 1, mp);
        }
    }
    vector<int> rightSideView(TreeNode* root) {
        map<int, int>mp;
        dfs(root, 0, mp);
        vector<int>ans;
        for(auto it: mp){
            ans.push_back(it.second);
        }
        return ans;
    }
};