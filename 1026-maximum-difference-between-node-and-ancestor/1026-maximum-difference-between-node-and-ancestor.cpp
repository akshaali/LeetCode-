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
    int maxAncestorDiff(TreeNode* root, int mn = 100000, int mx = 0) {
       if(root == NULL) return mx-mn;
        mn = min(root->val, mn);
        mx = max(root->val, mx);
        return max(maxAncestorDiff(root->left, mn,mx), maxAncestorDiff(root->right, mn,mx));
    }
};