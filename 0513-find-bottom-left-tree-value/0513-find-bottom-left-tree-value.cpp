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
    int findBottomLeftValue(TreeNode* root) {
        if (root == nullptr)
            return 0;
        queue<TreeNode*> nodeque;
        nodeque.push(root);
        vector<int> cur_level;
        while (!nodeque.empty()) {
            int size = nodeque.size();
            cur_level = vector<int>();
            for (int i = 0; i < size; i++) {
                TreeNode* cur = nodeque.front();
                nodeque.pop();
                cur_level.push_back(cur->val);
                if (cur->left)
                    nodeque.push(cur->left);
                if (cur->right)
                    nodeque.push(cur->right);
            }
        }
        return cur_level[0];
    }
};