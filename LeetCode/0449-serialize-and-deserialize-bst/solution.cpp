/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root) return "null";
        queue<TreeNode*> q;
        q.push(root);
        string res;
        while(!q.empty()){
            TreeNode* node=q.front();
            q.pop();
            if(node){
                res+=to_string(node->val)+",";
                q.push(node->left);
                q.push(node->right);
            }else{
                res+="null,";
            }
        }
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.empty() || data == "null") return NULL;
        stringstream s(data);
        string str;
        getline(s,str,',');
        TreeNode* root=new TreeNode(stoi(str));
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            TreeNode* node=q.front();
            q.pop();

            if(!getline(s,str,',')) break;
            if(str=="null"){
                node->left=NULL;
            }else{
                TreeNode* lN=new TreeNode(stoi(str));
                node->left=lN;
                q.push(lN);
            }

            if(!getline(s,str,',')) break;
            if(str=="null"){
                node->right=NULL;
            }else{
                TreeNode* rN=new TreeNode(stoi(str));
                node->right=rN;
                q.push(rN);
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;
