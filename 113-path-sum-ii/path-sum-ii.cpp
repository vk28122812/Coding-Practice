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
    vector<vector<int>>ans;
public:
    void dfs(TreeNode* root,vector<int>&path, int targetSum){
        if(!root){
            return;
        }
        if(!root->left && !root->right && (targetSum - root->val == 0)){
            ans.push_back(path);
            ans.back().push_back(root->val);
            return;
        }
        path.push_back(root->val);
        dfs(root->left, path, targetSum - root->val);
        dfs(root->right,path, targetSum - root->val);
        path.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int>path;
        dfs(root, path, targetSum);
        return ans;
    }
};