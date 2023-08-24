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
    vector<string>ans;
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<int> path;
        dfs(root, path);
        return ans;
    }
    void dfs(TreeNode* root, vector<int>& path) {
        if (root == nullptr) return;
        path.push_back(root->val);
        if (root->left == nullptr && root->right == nullptr) { // Is leaf node
            string pathStr = "";
            int n = path.size();
            for(int i = 0; i<n; i++){
                pathStr += to_string(path[i]);
                if(i<n-1){
                    pathStr += "->";
                }
            }
            ans.push_back(pathStr);
        } else {
            dfs(root->left, path);
            dfs(root->right, path);
        }
        path.pop_back(); // backtrack
    }
};