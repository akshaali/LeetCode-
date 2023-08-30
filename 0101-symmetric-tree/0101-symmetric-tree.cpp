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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p == NULL && q != NULL) return false;
        if(q == NULL && p != NULL) return false;
        if(p == NULL && q == NULL) return true;
        // cout<<"p->val: "<<p->val<< " q->val: "<<q->val<<endl;
        bool left = isSameTree(p->left, q->right);
        bool right = isSameTree(p->right, q->left);
        bool isSame = p->val == q->val;
        // cout<<"isSame: "<<isSame<<endl;
        if(left && right && isSame) return true;
        return false;
    }
    bool isSymmetric(TreeNode* root) {
        if(root == NULL) return true;
        return isSameTree(root->left, root->right);
    }
};