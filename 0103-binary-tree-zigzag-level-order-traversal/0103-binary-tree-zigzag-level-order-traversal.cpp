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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>res;
        if(root == NULL) return res;
        queue<TreeNode*> q;
        q.push(root);
        bool flag = false;
        while(!q.empty()) {
            vector<int>temp;
            int s=q.size();
            for(int i=0;i<s;i++) {
                TreeNode* t=q.front();
                q.pop();
                if(t->left) q.push(t->left);
                if(t->right) q.push(t->right);
                temp.push_back(t->val);
            }
            res.push_back(temp);
        }
        for(int i = 1; i<res.size(); i=i+2){
          reverse(res[i].begin(), res[i].end());
        }
        return res;        
    }
};