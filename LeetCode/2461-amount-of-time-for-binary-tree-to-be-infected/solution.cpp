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

    TreeNode *findNode(TreeNode *root, int val, unordered_map<int,TreeNode *> &parent, TreeNode *par)
    {
        if(root==NULL) return NULL;

        parent[root->val] = par;

        if(root->val==val) return root;

        TreeNode *left = findNode(root->left,val,parent,root);
        TreeNode *right = findNode(root->right,val,parent,root);

        if(left!=NULL) return left;
        return right;
    }

    int amountOfTime(TreeNode* root, int start) {
        unordered_map<int,TreeNode *>parent;
        unordered_map<int,bool>vis;
        TreeNode *node = findNode(root,start,parent,NULL);

        if(node==NULL) return 0;

        int timer = 0;

        queue<TreeNode *>q;
        vis[node->val] = true;
        if(parent[node->val]!=NULL) 
        {
            q.push(parent[node->val]);
            vis[parent[node->val]->val] = true;
        }

        if(node->left!=NULL)
        {
            q.push(node->left);
            vis[node->left->val]  = true;
        }

        if(node->right!=NULL)
        {
            q.push(node->right);
            vis[node->right->val] = true;
        }

        while(!q.empty())
        {
            int s = q.size();
            for(int i=0;i<s;i++)
            {
                auto front = q.front();
                q.pop();

                TreeNode *par = parent[front->val];
                if(par!=NULL  &&  vis.find(par->val)==vis.end())
                {
                    q.push(par);
                    vis[par->val] = true;
                }

                if(front->left!=NULL  &&  vis.find(front->left->val)==vis.end())
                {
                    q.push(front->left);
                    vis[front->left->val] = true;
                }

                if(front->right!=NULL  &&  vis.find(front->right->val)==vis.end())
                {
                    q.push(front->right);
                    vis[front->right->val] = true;
                }
            }

            timer++;
        }

        return timer;
    }
};
