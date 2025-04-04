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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root)return 0;
        if(root==p || root==q)return root;
        TreeNode* left = lowestCommonAncestor(root->left,p,q);
        TreeNode* right = lowestCommonAncestor(root->right,p,q);
        if(left && right)return root;
        else if(left)return left;
        else return right;
    }
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        if(!root)return root;
        int ht = height(root);
        vector<Node*> v;
        getDeepestLeaves(root,v,1,ht);
        return lowestCommonAncestor(root,v.front(),v.back());
    }
};