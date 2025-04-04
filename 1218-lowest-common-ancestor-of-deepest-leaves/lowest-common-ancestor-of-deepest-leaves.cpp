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
    typedef TreeNode Node;
public:
    int height(Node*root){
        if(!root)return 0;
        return 1 + max(height(root->left), height(root->right));
    }
    void getDeepestLeaves(Node*root,vector<Node*>&v, int d, int&ht){
        if(!root){
            return;
        }
        if(d==ht){
            v.push_back(root);
        }
        getDeepestLeaves(root->left,v,d+1,ht);
        getDeepestLeaves(root->right,v,d+1,ht);
    }
    void getPath(Node*root,Node*target,vector<Node*>&path,bool&found){
        if(found || !root)return;
        if(root==target){
            found = 1;
            return;
        }
        path.push_back(root);
        getPath(root->left,target,path,found);
        getPath(root->right,target,path,found);
        if(!found)path.pop_back();
    }
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        if(!root)return root;
        int ht = height(root);
        vector<Node*> v;
        getDeepestLeaves(root,v,1,ht);
        if(v.size()==1){
            return v.front();
        }
        vector<vector<Node*>>paths;
        for(Node* node: v){
            bool found = 0;
            vector<Node*> p;
            getPath(root,node,p,found);
            paths.push_back(p);
        }
        Node* ans = 0;
        for(int i=0;i<ht-1;i++){
            Node* node = paths[0][i];
            bool flag = 1;
            for(int j=1;j<paths.size();j++){
                if(paths[j][i] != node){
                    flag = 0;
                    break;
                }
            }
            if(!flag)break;
            ans = node;
        }
        return ans;
    }
};