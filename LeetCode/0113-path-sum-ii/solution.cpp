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
    void solve(TreeNode* root,vector<int>& sum,vector<vector<int>>& ans,int su,int targetSum){
        if(root==NULL){
            return;
        }
        su+=root->val;
        sum.push_back(root->val);
        if(root->left==NULL && root->right==NULL){
            if(su==targetSum){
                ans.push_back(sum);
            }
        }else{
            solve(root->left,sum,ans,su,targetSum);
            solve(root->right,sum,ans,su,targetSum);
        }
        sum.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> sum;
        vector<vector<int>> ans;
        int su=0;
        solve(root,sum,ans,su,targetSum);
        return ans;
    }
};
