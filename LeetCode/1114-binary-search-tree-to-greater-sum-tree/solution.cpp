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
    void gst(TreeNode* root,vector<int>& ans){
        if(!root) return;
        gst(root->left,ans);
        ans.push_back(root->val);
        gst(root->right,ans);
    }
    void gstTob(TreeNode* root,unordered_map<int,int>& mp){
        if(!root) return;
        gstTob(root->left,mp);
        root->val=mp[root->val];
        gstTob(root->right,mp);
    }
    TreeNode* bstToGst(TreeNode* root) {
        vector<int> ans;
        gst(root,ans);
        unordered_map<int,int> mp;
        int suffix = 0;
        for(int i = ans.size()-1; i >= 0; i--){
            suffix += ans[i];
            mp[ans[i]] = suffix;
        }
        gstTob(root,mp);
        return root;
    }
};
