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
    vector<int> inorderTraversal;
    void inorder(TreeNode* root){
        if(root == NULL) return;
        inorder(root->left);
        inorderTraversal.push_back(root->val);
        inorder(root->right);
    }
    bool findTarget(TreeNode* root, int k) {
        inorder(root);
        int n = inorderTraversal.size();
        int pt1 = 0, pt2 = n-1;
        while(pt1<pt2){
            int sum = inorderTraversal[pt1] + inorderTraversal[pt2];
            if(sum == k) return true;
            if(sum>k) pt2--;
            else pt1++;
        }
        return false;
    }
};