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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        if (nums.size() == 0)
            return nullptr;
        int idx = 0;
        int rootVal = 0;
        for (int i = 0; i < nums.size(); i++){
            if (nums[i] > rootVal){
                rootVal = nums[i];
                idx = i;
            }
        }
        TreeNode* root = new TreeNode(rootVal);
        vector<int> left_nums(nums.begin(), nums.begin() + idx);
        vector<int> right_nums(nums.begin() + idx + 1, nums.end());
        root->left = constructMaximumBinaryTree(left_nums);
        root->right = constructMaximumBinaryTree(right_nums);
        return root;
    }
};