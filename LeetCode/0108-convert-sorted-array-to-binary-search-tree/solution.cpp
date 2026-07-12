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
    TreeNode* sortedArrayToBST(vector<int>& ans) {
        TreeNode* node=build(ans,0,ans.size()-1);
        return node;
    }
    TreeNode* build(vector<int> A,int l,int r){
        if(l>r) return NULL;
        int mid=l+(r-l)/2;
        TreeNode* node=new TreeNode(A[mid]);
        node->left=build(A,l,mid-1);
        node->right=build(A,mid+1,r);
        return node;
    }
};
