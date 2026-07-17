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
    TreeNode* levelOrder(TreeNode* root) {
        if(root==NULL) return NULL;
        queue<TreeNode*> q;
        q.push(root);
        int lvle=0;
        while(!q.empty()){
            int size=q.size();
            vector<TreeNode*> lvl;
            for(int i=0;i<size;i++){
                TreeNode* node=q.front();
                q.pop();
                lvl.push_back(node);
                if(node->left!=NULL) q.push(node->left);
                if(node->right!=NULL) q.push(node->right);
            }
            if(lvle%2==1){
                int lft=0;int rgt=size-1;
                while(lft<rgt){
                    swap(lvl[lft]->val,lvl[rgt]->val);
                    lft++;
                    rgt--;
                }
            }
            lvle++;
        }
        return root;
    }
    TreeNode* reverseOddLevels(TreeNode* root) {
        TreeNode* node=levelOrder(root);
        return node;
    }
};
