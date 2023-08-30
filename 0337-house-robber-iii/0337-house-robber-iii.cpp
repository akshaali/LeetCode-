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
    pair<int,int> solve(TreeNode* root){
        if(root == NULL){
            pair<int,int> res = make_pair(0,0);
            return res;
        }
        if(root->left == NULL && root->right == NULL){
            pair<int,int> res = make_pair(root->val,0);
            return res;
        }
        pair<int,int> left = solve(root->left);
        pair<int,int> right = solve(root->right);
        
        pair<int,int> res;
        //inlclude 
        res.first = root->val + left.second + right.second;
        
        //exclude 
        res.second = max(left.first, left.second) + max(right.first, right.second);
        
        return res;
        
    }
    int rob(TreeNode* root) {
        pair<int,int>ans = solve(root);
        return max(ans.first, ans.second);
    }
};