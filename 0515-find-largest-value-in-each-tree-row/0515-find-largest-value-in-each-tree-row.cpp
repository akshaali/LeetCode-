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
    void solve(TreeNode* root, int row, vector<int> & ans){
        if(root == NULL) return;
        if(row>= ans.size()){
            ans.push_back(root->val);
        }else{
            ans[row] = max(ans[row], root->val);
        }
        solve(root->left, row+1, ans);
        solve(root->right, row+1, ans);
    }
    vector<int> largestValues(TreeNode* root) {
        vector<int> ans;
        solve(root, 0, ans);
        return ans;
    }
};