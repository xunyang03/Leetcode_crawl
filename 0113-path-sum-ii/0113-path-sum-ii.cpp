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
    vector<vector<int>> allpath_;
    vector<int> path_;
public:
    void traverse(TreeNode* node, int rest){
        if (!node->left && !node->right && rest == node->val){
            allpath_.push_back(path_);
            return;
        }
        if (!node->left && !node->right) return;
       
        if (node->left) {
            path_.push_back(node->left->val);
            traverse(node->left, rest-node->val);
            path_.pop_back();
        }
        if (node->right) {
            path_.push_back(node->right->val);
            traverse(node->right, rest-node->val);
            path_.pop_back();
        }
        return;
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        allpath_ = vector<vector<int>>();
        if (root == nullptr)
            return allpath_;
        path_ = {root->val};
        traverse(root, targetSum);
        return allpath_;
    }
};