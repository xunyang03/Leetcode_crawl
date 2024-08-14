/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
private:
    int result_ = INT_MAX;
    TreeNode* prev_ = nullptr;

public:
    void inorder(TreeNode* node) {
        if (!node)
            return;
        inorder(node->left);
        if (prev_)
            result_ = min(result_, abs(prev_->val - node->val));
        prev_ = node;
        inorder(node->right);
    }

    int getMinimumDifference(TreeNode* root) {
        inorder(root);
        return result_;
    }
};