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
    bool isCousins(TreeNode* root, int x, int y) {
        if(root == NULL) return false;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            int s=q.size();
            bool isXExist = false;
            bool isYExist = false;
            for(int i=0;i<s;i++) {
                TreeNode* t=q.front();
                q.pop();
                if(t->val == x) isXExist = true;
                if(t->val == y) isYExist = true;
                if(t->left && t->right){
                    if(t->left->val == x && t->right->val == y) return false;
                    if(t->left->val == y && t->right->val == x) return false;
                }
                if(t->left) q.push(t->left);
                if(t->right) q.push(t->right);
            }
            if(isXExist && isYExist) return true;
        }
        return false;
    }
};