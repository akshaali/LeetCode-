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
class BSTIterator {
public:
    TreeNode* node;
    void flattenBST(TreeNode* root, TreeNode* &prev){
        if(root == NULL) return;
        flattenBST(root->left, prev);
        prev->left = NULL;
        prev->right = root;
        prev = root;
        flattenBST(root->right, prev);
    }
    BSTIterator(TreeNode* root) {
        TreeNode* dummy = new TreeNode(-1);
        TreeNode* prev = dummy;
        flattenBST(root, prev);
        prev->left = NULL;
        prev->right = NULL;
        node = dummy->right;
        delete dummy;
    }
    
    int next() {
        int ans = node->val;
        node = node->right;
        return ans;
    }
    
    bool hasNext() {
        if(node){
            return true;
        }
        return false;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */