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
    int maxDepth(TreeNode* root) {
        if(root==NULL) return 0;
        int lh=maxDepth(root->left);
        int rh=maxDepth(root->right);
        return (1+max(lh,rh));
    }
    void sum(TreeNode* root,int h,int m,int& ans){
        if(!root) return;
        sum(root->left,h,m+1,ans);
        sum(root->right,h,m+1,ans);
        if(m==h){
            ans+=(root->val);
        }
    }
    int deepestLeavesSum(TreeNode* root) {
        int h=maxDepth(root);
        int m=1;
        int ans=0;
        sum(root,h,m,ans);
        return ans;
    }
};
