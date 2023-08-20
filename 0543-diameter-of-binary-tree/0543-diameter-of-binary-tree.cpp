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
        return rightHeight+1;
    }
    int classicDiameterOfBinaryTree(TreeNode* root){
        if(root == NULL) return 0;
        int opt1 = classicDiameterOfBinaryTree(root->left);
        int opt2 = classicDiameterOfBinaryTree(root->right);
        int opt3 = height(root->left) + height(root->right);
        int ans = max({opt1, opt2, opt3});
        return ans;
    }
    pair<int, int> diameterOfBinaryTreeFast(TreeNode* root){
        if(root == NULL){
            pair<int, int> p = make_pair(0,0);
            return p;
        }
        pair<int, int> left = diameterOfBinaryTreeFast(root->left);
        pair<int, int> right = diameterOfBinaryTreeFast(root->right);
        
        int opt1 = left.first;
        int opt2 = right.first;
        int opt3 = left.second + right.second;
        
        pair<int, int> ans;
        ans.first = max({opt1, opt2, opt3});
        ans.second = max(left.second, right.second) + 1;
        
        return ans;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        return diameterOfBinaryTreeFast(root).first;
    }
};