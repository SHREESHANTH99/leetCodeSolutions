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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        map<int,int> mp;
        for(int i=0;i<inorder.size();i++){
            mp[inorder[i]]=i;
        }
        TreeNode* root=buildT(postorder,0,postorder.size()-1,inorder,0,inorder.size()-1,mp);
        return root;
    }
    TreeNode* buildT(vector<int>& postorder,int pS,int pE,vector<int>& inorder,int iS,int iE,map<int,int>& mp){
        if(pS>pE || iS>iE){
            return NULL;
        }
        TreeNode* root=new TreeNode(postorder[pE]);
        int inRoot=mp[postorder[pE]];
        int numsL=inRoot-iS;
        root->left=buildT(postorder,pS,pS+numsL-1,inorder,iS,inRoot-1,mp);
        root->right=buildT(postorder,pS+numsL,pE-1,inorder,inRoot+1,iE,mp);
        return root;
    }
};
