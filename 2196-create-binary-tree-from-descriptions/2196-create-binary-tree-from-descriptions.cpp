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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int, TreeNode*>nodes;
        unordered_set<int> children;
        TreeNode* root;
        for(int i = 0; i<descriptions.size(); i++){

            int parent = descriptions[i][0];
            int child = descriptions[i][1];
            int direction = descriptions[i][2];

            TreeNode* parentNode;
            TreeNode* childNode;

            if(nodes.count(parent)) parentNode = nodes[parent];
            else parentNode = new TreeNode(parent);

            if(nodes.count(child)) childNode = nodes[child];
            else childNode = new TreeNode(child);

            if(direction == 1) parentNode->left = childNode;
            if(direction == 0) parentNode->right = childNode;

            nodes[parent] = parentNode;
            nodes[child] = childNode;

            children.insert(child);
        }
        for (auto& [value, node] : nodes) {
            if (children.count(value) == 0) {
                root = node;
                break;
            }
        }
        return root;
    }
};