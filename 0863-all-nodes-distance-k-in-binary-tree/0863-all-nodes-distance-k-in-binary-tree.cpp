/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    unordered_map<TreeNode*, TreeNode*> track_parent;
    void markParent(TreeNode* root){
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int n = q.size();
            for(int i = 0; i<n; i++){
                TreeNode* temp = q.front();
                q.pop();
                if(temp->left){
                    track_parent[temp->left] = temp;
                    q.push(temp->left);
                }
                if(temp->right){
                    track_parent[temp->right] = temp;
                    q.push(temp->right);
                }
            }
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        markParent(root);
        unordered_map<TreeNode*, bool> visited;
        queue<TreeNode*> q;
        q.push(target);
        visited[target] = true;
        int currLevel = 0;
        while(!q.empty()){
            if(currLevel++ == k) break;
            int n = q.size();
            for(int i = 0; i<n; i++){
                TreeNode* temp = q.front();
                q.pop();
                if(temp->left && !visited[temp->left]){
                    q.push(temp->left);
                    visited[temp->left] = true;
                }
                if(temp->right && !visited[temp->right]){
                    q.push(temp->right);
                    visited[temp->right] = true;
                    
                }
                if(track_parent[temp] && !visited[track_parent[temp]]){
                    q.push(track_parent[temp]);
                    visited[track_parent[temp]] = true;
                }
            }
        }
        vector<int> ans;
        while(!q.empty()){
            TreeNode* temp = q.front();
            q.pop();
            ans.push_back(temp->val);
        }
        return ans;
    }
};










