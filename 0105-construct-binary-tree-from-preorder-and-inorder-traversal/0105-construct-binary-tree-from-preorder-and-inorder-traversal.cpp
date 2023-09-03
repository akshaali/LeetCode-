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
    int n;
    int findPosition(vector<int>& inorder, int ele){
        for(int i = 0; i<n; i++){
            if(inorder[i] == ele) return i;
        }
        return -1;
    }
    TreeNode* solve(vector<int>& preorder, vector<int>& inorder, int inorderStartIndex, int inorderEndIndex, int &index){
        // cout<<"inorderStartIndex: "<<inorderStartIndex<<" inorderEndIndex: "<<inorderEndIndex<<endl;
        if(inorderStartIndex>inorderEndIndex || index>=n){
            return NULL;
        }
        int ele = preorder[index++];
        TreeNode* node = new TreeNode(ele);
        int position = findPosition(inorder, ele);
        // cout<<"position: "<<position<<" ele: "<<ele<<endl;
        node->left = solve(preorder, inorder, inorderStartIndex, position-1, index);
        node->right = solve(preorder, inorder, position+1, inorderEndIndex, index);
        
        return node;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        n = preorder.size();
        int index = 0;
        TreeNode* root = solve(preorder, inorder, 0, n-1, index);
        return root;
        
    }
};