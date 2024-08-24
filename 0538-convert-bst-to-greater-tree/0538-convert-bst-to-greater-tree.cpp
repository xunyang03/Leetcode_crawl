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
    int sum;

public:
    TreeNode* recurse(TreeNode* root) {
        if (!root)
            return root;
        root->right = recurse(root->right);
        // 单层递归逻辑
        sum += root->val;
        root->val = sum;
        root->left = recurse(root->left);
        return root;
    }

    TreeNode* convertBST(TreeNode* root) {
        sum = 0;
        return recurse(root);
    }
};