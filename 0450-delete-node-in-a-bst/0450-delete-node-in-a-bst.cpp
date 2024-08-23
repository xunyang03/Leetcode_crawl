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
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root)
            return root;
        if (root->val == key) {
            if (!root->left && !root->right) {
                delete root;
                return nullptr;
            } else if (root->left && !root->right) {
                TreeNode* lefttop = root->left;
                delete root;
                return lefttop;
            } else if (!root->left && root->right) {
                TreeNode* righttop = root->right;
                delete root;
                return righttop;
            } else {
                TreeNode* lefttop = root->left;
                TreeNode* righttop = root->right;
                TreeNode* cur = root->right;
                while (cur->left)
                    cur = cur->left;
                cur->left = lefttop;
                delete root;
                return righttop;
            }
        }
        if (root->val > key)
            root->left = deleteNode(root->left, key);
        if (root->val < key)
            root->right = deleteNode(root->right, key);
        return root;
    }
};