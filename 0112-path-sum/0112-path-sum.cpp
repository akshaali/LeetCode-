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
    bool found = false;
    bool dfs(TreeNode* root, int targetSum, int pathSum){
        if(found) return true;
        if(root->left == NULL && root->right == NULL && pathSum == targetSum){
            found = true;
            return true;
        }
        bool left = false;
        bool right = false;
        if(root->left){
            left = dfs(root->left, targetSum, pathSum+root->left->val);
        }
        if(root->right){
            right = dfs(root->right, targetSum, pathSum+root->right->val);
        }
        return left || right;
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(!root) return false;
        dfs(root, targetSum, root->val);
        return found;
//         queue<pair<TreeNode*, int>>q;
//         q.push(make_pair(root, root->val));
//         while(!q.empty()){
//             int n = q.size();
//             pair<TreeNode*, int> temp = q.front();
//             q.pop();
//             TreeNode* treeNode = temp.first;
//             int pathSum = temp.second;
//             if(treeNode->left == NULL && treeNode->right == NULL && pathSum == targetSum){
//                 return true;
//             }
//             for(int i = 0; i<n; i++){
//                 if(treeNode->left){
//                     q.push(make_pair(treeNode->left, pathSum+treeNode->left->val));
//                 }
//                 if(treeNode->right){
//                     q.push(make_pair(treeNode->right, pathSum+treeNode->right->val));
//                 }
//             }
//         }
        
//         return false;
    }
};