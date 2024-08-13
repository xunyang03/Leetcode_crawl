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
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if (!root1)
            return root2;
        if (!root2)
            return root1;
        queue<TreeNode*> tree;
        tree.push(root1);
        tree.push(root2);
        while (!tree.empty()) {
            TreeNode* node1 = tree.front();
            tree.pop();
            TreeNode* node2 = tree.front();
            tree.pop();
            node1->val += node2->val;
            if (node1->left && node2->left) {
                tree.push(node1->left);
                tree.push(node2->left);
            }
            else if (!node1->left && node2->left) 
                node1->left = node2->left;
            if (node1->right && node2->right) {
                tree.push(node1->right);
                tree.push(node2->right);
            }
            else if (!node1->right && node2->right)
                node1->right = node2->right;        
        }
        return root1;
    }
};