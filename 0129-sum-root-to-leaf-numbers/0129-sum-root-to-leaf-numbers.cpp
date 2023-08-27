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
    int ans = 0;
    void dfs(TreeNode* root, int sum){
        if(root == NULL) return;
        if(root->left == NULL && root->right == NULL){
            sum = sum*10 + root->val;
            ans += sum;
            return;
        }
        dfs(root->left, sum*10+root->val);
        dfs(root->right, sum*10+root->val);
    }
    int sumNumbers(TreeNode* root) {
        dfs(root, 0);
        return ans;
    }
};