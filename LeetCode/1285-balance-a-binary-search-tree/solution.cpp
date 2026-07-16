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
    void inorder(TreeNode* root,vector<int>& ans){
        if(!root){
            return;
        }
        inorder(root->left,ans);
        ans.push_back(root->val);
        inorder(root->right,ans);
    }
    TreeNode* arryToBst(vector<int>& A,int l,int r){
        if(l>r){
            return NULL;
        }
        int mid=l+(r-l)/2;
        TreeNode* node=new TreeNode(A[mid]);
        node->left=arryToBst(A,l,mid-1);
        node->right=arryToBst(A,mid+1,r);
        return node;
    }
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> ans;
        inorder(root,ans);
        TreeNode* node=arryToBst(ans,0,ans.size()-1);
        return node;
    }
};
