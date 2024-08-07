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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p == nullptr && q == nullptr)
            return true;
        else if (p == nullptr || q == nullptr)
            return false;
        else if (p->val != q->val)
            return false;
        else
            return isSameTree(p->left, q->left) &&
                   isSameTree(p->right, q->right);
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (root == nullptr)
            return false;
        if (isSameTree(root, subRoot))
            return true;
        else {
            bool leftleaf = isSubtree(root->left, subRoot);
            bool rightleaf = isSubtree(root->right, subRoot);
            return leftleaf || rightleaf;
        }
    }
};