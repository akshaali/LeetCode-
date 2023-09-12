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
class Info {
public:
    int mini;
    int maxi;
    int sum;
    bool isValid;
};
class Solution {
public:
    int maxSum = 0;
    Info solve(TreeNode* root){
        if(root == NULL) {
            return {INT_MAX, INT_MIN, 0, true};
        }
        if(root->left == NULL && root->right == NULL){
            maxSum = max(maxSum, root->val);
            return {root->val, root->val, root->val, true};
        }
        Info left = solve(root->left);
        Info right = solve(root->right);
        
        Info currNode;
        currNode.mini = min(left.mini, root->val);
        currNode.maxi = max(root->val, right.maxi);
        currNode.sum = left.sum + right.sum + root->val;
        cout<<left.isValid<<" "<<right.isValid<<" "<<left.maxi<<" "<<right.mini<<endl;
        if(root->val > left.maxi && root->val < right.mini && left.isValid && right.isValid){
            currNode.isValid = true;
        }else{
            currNode.isValid = false;
        }
        // cout<<"root "<<root->val<<endl;
        // cout<<"currNode.isValid "<<currNode.isValid<<" sum: "<<currNode.sum<<endl;
        if(currNode.isValid){
            maxSum = max(maxSum, currNode.sum);
        }
        return currNode;
    }
    int maxSumBST(TreeNode* root) {
        solve(root);
        return maxSum;
    }
};