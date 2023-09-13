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
    vector<int> ans;
    int maxCount = 0;
    int currCount = 0;
    int modeCount = 0;
    int currVal;
    void handleMode(int val){
        if(val != currVal){
            currVal = val;
            currCount = 0;
        }
        currCount++;
        // cout<<"maxCount: "<<maxCount<<" currCount: "<<currCount<<endl;
        if(currCount>maxCount){
            maxCount = currCount;
            modeCount = 1;
        }else if(maxCount == currCount){
            // cout<<"====>>>>> "<<ans.size()<<" ======= "<<modeCount<<endl;
            if(ans.size()){
                ans[modeCount] = val;
            }
            modeCount++;
        }
        
    }
    void inorderTraversal(TreeNode* root){
        if(root == NULL) return;
        inorderTraversal(root->left);
        handleMode(root->val);
        inorderTraversal(root->right);
        
    }
    vector<int> findMode(TreeNode* root) {
        inorderTraversal(root);
        ans.resize(modeCount);
         // cout<<"maxCount: "<<maxCount<<" modeCount: "<<modeCount<<endl;
        modeCount = 0;
        currCount = 0;
       
        inorderTraversal(root);
        return ans;
    }
};