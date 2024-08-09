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
    void preorder(TreeNode* node, string path, vector<string>& result) {
        path += to_string(node->val);
        if (node->left == nullptr && node->right == nullptr) {
            result.push_back(path);
            return;
        }
        if (node->left)
            preorder(node->left, path + "->", result);
        if (node->right)
            preorder(node->right, path + "->", result);
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> result;
        string path;
        preorder(root, path, result);
        return result;
    }
};