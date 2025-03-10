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
private:
    int cnt_;
public:
    int coinNodeCount(TreeNode* node){
        if (node == nullptr)
            return 0;  
        int leftcnt = coinNodeCount(node->left);
        int rightcnt = coinNodeCount(node->right);
        cnt_ += abs(leftcnt) + abs(rightcnt);        
        return leftcnt + rightcnt + node->val - 1;
    }
    
    int distributeCoins(TreeNode* root) {
        if (root == nullptr) return 0;
        cnt_ = 0;
        coinNodeCount(root);
        return cnt_;
    }
};