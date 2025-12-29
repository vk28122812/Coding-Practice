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
        path.push_back(root->val);
        targetSum -= root->val;
    
        dfs(root->left, path, targetSum);
        dfs(root->right,path, targetSum);

        if(targetSum == 0 && !root->left && !root->right){
            ans.push_back(path);
        }

        targetSum += root->val;
        path.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int>path;
        dfs(root, path, targetSum);
        return ans;
    }
};