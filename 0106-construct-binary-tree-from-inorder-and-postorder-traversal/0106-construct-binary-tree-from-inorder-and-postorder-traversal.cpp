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
    int n;
    int findPosition(vector<int>& inorder, int ele){
        for(int i = 0; i<n; i++){
            if(inorder[i] == ele) return i;
        }
        return -1;
    }
    TreeNode* solve(vector<int>& postorder, vector<int>& inorder, int inorderStartIndex, int inorderEndIndex, int &index){
        // cout<<"inorderStartIndex: "<<inorderStartIndex<<" inorderEndIndex: "<<inorderEndIndex<<endl;
        if(inorderStartIndex>inorderEndIndex || index<0){
            return NULL;
        }
        int ele = postorder[index--];
        TreeNode* node = new TreeNode(ele);
        int position = findPosition(inorder, ele);
        // cout<<"position: "<<position<<" ele: "<<ele<<endl;
        
        node->right = solve(postorder, inorder, position+1, inorderEndIndex, index);
        node->left = solve(postorder, inorder, inorderStartIndex, position-1, index);
        
        return node;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        n = postorder.size();
        int index = n-1;
        TreeNode* root = solve(postorder, inorder, 0, n-1, index);
        return root;
    }
};