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
    int result;
    int traversal(TreeNode* cur) {

        // 空节点，该节点有覆盖
        if (cur == NULL) return 2;

        int left = traversal(cur->left);    // 左
        int right = traversal(cur->right);  // 右

        // 情况1  左右节点都有覆盖
        if (left == 2 && right == 2) return 0;

        // 情况2  左或右存在无覆盖
        if (left == 0 || right == 0) {
            result++;
            return 1;
        }

        // 情况3  左或右已有摄像头
        if (left == 1 || right == 1) return 2;

        return -1;
    }

public:
    int minCameraCover(TreeNode* root) {
        result = 0;
        // 情况4 根节点需要摄像头
        if (traversal(root) == 0) { // root 无覆盖
            result++;
        }
        return result;
    }
};