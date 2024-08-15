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
    int maxCnt;
    int curCnt;
    vector<int> result;
    TreeNode* prev = nullptr;

public:
    void inorder(TreeNode* node) {
        if (!node)
            return;
        inorder(node->left);
        if (!prev)
            curCnt = 1;
        else if (prev->val == node->val)
            curCnt++;
        else
            curCnt = 1;
        prev = node;
        if (curCnt == maxCnt)
            result.push_back(node->val);
        else if (curCnt > maxCnt) {
            result.clear();
            result.push_back(node->val);
            maxCnt = curCnt;
        }
        inorder(node->right);
        return;
    }
    vector<int> findMode(TreeNode* root) {
        maxCnt = 0;
        curCnt = 0;
        result.clear();
        inorder(root);
        return result;
    }
};