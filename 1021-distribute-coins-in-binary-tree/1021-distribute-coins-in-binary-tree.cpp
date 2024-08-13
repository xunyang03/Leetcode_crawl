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
    int coinNodeCount(TreeNode* node, int& cnt){
        if (node == nullptr)
            return 0;  
        int leftcnt = coinNodeCount(node->left, cnt);
        int rightcnt = coinNodeCount(node->right, cnt);
        cnt += abs(leftcnt) + abs(rightcnt);        
        return leftcnt + rightcnt + node->val - 1;
    }
    
    int distributeCoins(TreeNode* root) {
        if (root == nullptr) return 0;
        int result = 0;
        coinNodeCount(root, result);
        return result;
    }
};