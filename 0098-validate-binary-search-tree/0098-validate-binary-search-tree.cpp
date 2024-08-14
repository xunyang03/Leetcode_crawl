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
    TreeNode* prev = nullptr; // record previous node

    bool isValidBST(TreeNode* root) {
        if (!root)
            return true;        
        bool leftbool = isValidBST(root->left);
        if (prev && prev->val >= root->val) return false;
        else prev = root;
        bool rightbool = isValidBST(root->right);
        return leftbool && rightbool;
    }
};