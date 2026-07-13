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
    void solve(TreeNode* root,int sum,vector<int>& ans){
        if(root==NULL){
            return;
        }
        sum+=root->val;
        if(root->left==NULL && root->right==NULL){
            ans.push_back(sum);
        }else{
            solve(root->left,sum,ans);
            solve(root->right,sum,ans);
        }
        sum=0;
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        int sum=0;
        vector<int> ans;
        solve(root,sum,ans);
        for(int i=0;i<ans.size();i++){
            if(ans[i]==targetSum){
                return true;
            }
        }
        return false;
    }
};
