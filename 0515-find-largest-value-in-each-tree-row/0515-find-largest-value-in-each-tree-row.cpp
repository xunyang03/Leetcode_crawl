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
    vector<int> largestValues(TreeNode* root) {
        vector<int> result;
        queue<TreeNode*> nodeque;
        if (root != nullptr) nodeque.push(root);
        while (! nodeque.empty()){
            int size = nodeque.size();
            int level_max = INT_MIN;
            for (int i = 0; i < size; i++){
                TreeNode* cur = nodeque.front();
                nodeque.pop();
                level_max = cur->val > level_max? cur->val : level_max;
                if (cur->left) nodeque.push(cur->left);
                if (cur->right) nodeque.push(cur->right);
            }            
            result.push_back(level_max);
        }
        return result;
        }
};