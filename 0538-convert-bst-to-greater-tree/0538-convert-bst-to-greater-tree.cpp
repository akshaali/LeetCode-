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
    int currSum = 0;
    void solve(TreeNode* &root){
        if(root == NULL) return;
        solve(root->right);
        int temp = root->val;
        root->val += currSum;
        currSum += temp;
        solve(root->left);
    }
    TreeNode* convertBST(TreeNode* root) {
        solve(root);
        return root;
    }
};