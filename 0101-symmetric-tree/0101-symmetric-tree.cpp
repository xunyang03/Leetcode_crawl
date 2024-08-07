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
    bool check(TreeNode* node1, TreeNode* node2) {
        if ((node1 == nullptr && node2 != nullptr) ||
            (node2 == nullptr && node1 != nullptr))
            return false;
        else if (node1 == nullptr && node2 == nullptr)
            return true;
        else if (node1->val != node2->val)
            return false;
        else {
            bool outer = check(node1->left, node2->right);
            bool inner = check(node1->right, node2->left);
            return outer && inner;
        }
    }

    bool isSymmetric(TreeNode* root) {
        if (root == nullptr)
            return true;
        return check(root->left, root->right);
    }
};