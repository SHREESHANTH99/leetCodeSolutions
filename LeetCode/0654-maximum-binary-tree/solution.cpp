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
    TreeNode* helper(vector<int>& nums,int l,int r){
        if(l>r){
            return NULL;
        }
        int mxIdx=l;
        for(int i=l;i<=r;i++){
            if(nums[i]>nums[mxIdx]){
                mxIdx=i;
            }
        }
        TreeNode* node=new TreeNode(nums[mxIdx]);
        node->left=helper(nums,l,mxIdx-1);
        node->right=helper(nums,mxIdx+1,r);
        return node;
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return helper(nums,0,nums.size()-1);
    }
};
