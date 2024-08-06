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
    int minDepth(TreeNode* root) {
        if (root == nullptr)
            return 0;
        queue<TreeNode*> nodeque;
        nodeque.push(root);
        int depth = 0;
        while (!nodeque.empty()) {
            int size = nodeque.size();
            depth++;
            for (int i = 0; i < size; i++) {
                TreeNode* cur = nodeque.front();
                nodeque.pop();
                if (cur->left)
                    nodeque.push(cur->left);
                if (cur->right)
                    nodeque.push(cur->right);
                if (!cur->left && !cur->right)
                    return depth;
            }
        }
        return depth;
    }
};