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
using namespace std;
class Solution {
public:
    unordered_map<TreeNode*, TreeNode*> mark_parent;
    TreeNode* targetNode;
    int ans = 0;
    void mapParent(TreeNode* root, int start){
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int n = q.size();
            for(int i = 0; i<n; i++){
                TreeNode* temp = q.front();
                q.pop();
                if(temp->val == start) targetNode = temp;
                if(temp->left){
                    mark_parent[temp->left] = temp;
                    q.push(temp->left);
                }
                if(temp->right){
                    mark_parent[temp->right] = temp;
                    q.push(temp->right);
                }
            }
        }
    }
    void burnTree(TreeNode* start){
        unordered_map<TreeNode*, bool> visited;
        queue<TreeNode*> q;
        q.push(start);
        visited[start] = true;
        while(!q.empty()){
            int n = q.size();
            bool burned = false;
            for(int i = 0; i<n; i++){
                TreeNode* temp = q.front();
                q.pop();
                if(temp->left && !visited[temp->left]){
                    q.push(temp->left);
                    visited[temp->left] = true;
                    burned= true;
                }
                
                if(temp->right && !visited[temp->right]){
                    q.push(temp->right);
                    visited[temp->right] = true;
                     burned= true;
                }
                
                if(mark_parent[temp] && !visited[mark_parent[temp]]){
                    q.push(mark_parent[temp]);
                    visited[mark_parent[temp]] = true;
                    burned= true;
                }
            }
            if(burned){
                ans++;
            }
        }
    }
    int amountOfTime(TreeNode* root, int start) {
        mapParent(root, start);
        burnTree(targetNode);
        return ans;
    }
};