using namespace std;
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
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*>q;
        q.push(root);
        int level = 0;
        int minLevel = 0, maxi = INT_MIN;
        while(!q.empty()){
            int n = q.size();
            int sum = 0;
            level++;
            for(int i = 0; i<n; i++){
                TreeNode* temp = q.front();
                q.pop();
                sum += temp->val;
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
            }
            if(maxi<sum){
                minLevel = level;
                maxi = sum;
            }
            // cout<<"minLevel: "<<minLevel<<" sum: "<<sum<<" level: "<<level<<endl;
        }
        return minLevel;
    }
};