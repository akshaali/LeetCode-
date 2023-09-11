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
    TreeNode* lca;
    int deepest;
    int solve(TreeNode* root, int depth){
        deepest = max(deepest, depth);
        if(root == NULL) return depth;
        int left = solve(root->left, depth+1);
        int right = solve(root->right, depth+1);
        if(left == deepest && right == deepest){
            lca = root;
        }
        return max(left, right);
    }
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
       solve(root, 0);
        return lca;
    }
};