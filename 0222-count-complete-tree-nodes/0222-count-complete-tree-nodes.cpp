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
    int leftHeight(TreeNode* root){
        int height = 0;
        while(root){
            height++;
            root = root->left;
        }
        // cout<<"height: "<<height<<endl;
        return height;
    }
    int rightHeight(TreeNode* root){
        int height = 0;
        while(root){
            height++;
            root= root->right;
        }
        return height;
        
    }
    int countNodes(TreeNode* root) {
        if(root == NULL) return 0;
        // cout<<"root: "<<root->val<<endl;
        int lh = leftHeight(root);
        int rh = rightHeight(root);
        // cout<<"lh: "<<lh<<" rh: "<<rh<<endl;
        if(lh == rh) return (1<<rh) - 1;
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};







