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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        queue<TreeNode*> store;
        if (root != nullptr) store.push(root);
        while (!store.empty()) {
            vector<int> cur_level;
            int cur_level_size = store.size();
            for (int i = 0; i < cur_level_size; i++) {
                TreeNode* cur_node = store.front();
                cur_level.push_back(cur_node->val);
                store.pop();
                if (cur_node->left)
                    store.push(cur_node->left);
                if (cur_node->right)
                    store.push(cur_node->right);
            }
            result.push_back(cur_level);
        }
        return result;
    }
};