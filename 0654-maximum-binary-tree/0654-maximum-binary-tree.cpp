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
    int findMaxIndex(int start, int end, vector<int>& nums){
        int maxIndex = start;
        while(start<=end){
            if(nums[start]>nums[maxIndex]){
                maxIndex = start;
            }
            start++;
        }
        return maxIndex;
    }
    TreeNode* solve(int start, int end, vector<int>& nums){
        if(start>=nums.size() || start>end) return NULL;
        int maxIndex = findMaxIndex(start, end, nums);
        TreeNode* node = new TreeNode(nums[maxIndex]);
        node->left = solve(start, maxIndex-1, nums);
        node->right = solve(maxIndex+1, end, nums);
        return node;
    }
    
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return solve(0, nums.size()-1, nums);
    }
};