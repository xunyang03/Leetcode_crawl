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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        queue<TreeNode*> rootque;
        if (root != nullptr) rootque.push(root);
        while (!rootque.empty()){
            int size = rootque.size();
            for (int i = 0; i < size; i++){
                TreeNode* cur = rootque.front();
                rootque.pop();
                if (i == size-1) result.push_back(cur->val);
                if (cur->left != nullptr) rootque.push(cur->left);
                if (cur->right != nullptr) rootque.push(cur->right);
            }
        }
        return result;
    }
};