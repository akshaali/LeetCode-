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
    TreeNode* replaceValueInTree(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        root->val = 0;
        while(!q.empty()){
            int n = q.size();
            vector<TreeNode*>level;
            int sum = 0;
            for(int i = 0; i<n; i++){
                TreeNode* temp = q.front();
                q.pop();
                level.push_back(temp);
                if(temp->left){
                    q.push(temp->left);
                    sum += temp->left->val;
                }
                if(temp->right){
                    q.push(temp->right);
                    sum += temp->right->val;
                }
                
            }
            for(auto t: level){
                int levelSum = sum;
                if(t->left) levelSum -= t->left->val;
                if(t->right) levelSum -= t->right->val;
                if(t->left) t->left->val = levelSum;
                if(t->right) t->right->val = levelSum;
            }
        }
        return root;
    }
};