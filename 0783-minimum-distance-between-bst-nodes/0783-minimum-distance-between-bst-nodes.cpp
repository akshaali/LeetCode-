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
    int mini = INT_MAX;
    void solve(TreeNode* root, int &val){
        if(root == NULL) return;
        solve(root->left, val);
        mini = min(mini, abs(root->val - val));
        val = root->val;
        solve(root->right, val);
    }
    int minDiffInBST(TreeNode* root) {
        int val = INT_MAX;
        solve(root, val);
        return mini;
    }
};