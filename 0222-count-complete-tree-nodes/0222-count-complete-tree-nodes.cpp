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
    int countNodes(TreeNode* root) {
        if (root == nullptr) return 0;
        TreeNode* left_tree = root->left;
        TreeNode* right_tree = root->right;
        int leftDepth, rightDepth = 0;
        while(left_tree){
            left_tree = left_tree->left;
            leftDepth++;
        }
        while(right_tree){
            right_tree = right_tree->right;
            rightDepth++;
        }
        if (leftDepth == rightDepth){
            return pow(2, leftDepth + 1) - 1;
        }
        return countNodes(root->left) + countNodes(root->right) + 1;
    }
};