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
    int height(TreeNode* root){
        if(root == NULL) return 0;
        int leftHeight = height(root->left);
        int rightHeight = height(root->right);
        if(leftHeight>rightHeight) return leftHeight+1;
        return rightHeight +1;
    }
    void levelSum(TreeNode* root, int& sum, int level){
        if(level == 0) return;
        if(level == 1 && root != NULL) {
            sum += root->val;
        }else{
            if(root->left != NULL)levelSum(root->left, sum, level-1);
            if(root->right != NULL)levelSum(root->right, sum, level-1);
        }
        
    }
    int deepestLeavesSum(TreeNode* root) {
        int h = height(root);
        int sum = 0;
        levelSum(root, sum, h);
        return sum;
    }
};