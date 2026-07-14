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
    unordered_map<int,int> cnt;
    int maxCnt=0;
    int inorder(TreeNode* root){
        if(!root) return 0;
        int s=inorder(root->left)+inorder(root->right)+root->val;
        maxCnt=max(maxCnt,++cnt[s]);
        return s;
    }
    vector<int> findFrequentTreeSum(TreeNode* root) {
        vector<int> ans;
        inorder(root);
        for(auto& s:cnt){
            if(s.second==maxCnt){
                ans.push_back(s.first);
            }
        }
        return ans;
    }
};
