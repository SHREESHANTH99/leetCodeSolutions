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
private:
    TreeNode* fst;
    TreeNode* prev;
    TreeNode* mid;
    TreeNode* last;
private:
    void inorder(TreeNode* root){
        if(root==NULL) return;
        inorder(root->left);
        if(prev!=NULL && (root->val <prev->val)){
            if(fst==NULL){
                fst=prev;
                mid=root;
            }
            else{
                last=root;
            }
        }
        prev=root;
        inorder(root->right);
    }
public:
    void recoverTree(TreeNode* root) {
        fst=mid=last=NULL;
        prev=new TreeNode(INT_MIN);
        inorder(root);
        if(fst && last) swap(fst->val ,last->val);
        else if(fst && mid) swap(fst->val,mid->val);
    } 
};
