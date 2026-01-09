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
    pair<TreeNode*,int> solve(TreeNode* node, int c){
        if(!node)return {node, c};
        auto l = solve(node->left, c+1);
        auto r = solve(node->right, c+1);

        if(l.first == 0 && r.first == 0){
            return {node, l.second};
        }else if(l.first == 0){
            return r;
        }else if(r.first == 0){
            return l;
        }else{
            if(l.second == r.second){
                return {node, l.second};
            }else if(l.second > r.second){
                return l;
            }else{
                return r;
            }
        }
    }
    
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        return solve(root, 0).first;
    }
};