/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> result;
        queue<Node*> nodeque;
        if (root != nullptr) nodeque.push(root);
        while (!nodeque.empty()){
            int size = nodeque.size();
            vector<int> cur_level;
            for (int i = 0; i < size; i++){
                Node* cur = nodeque.front();
                nodeque.pop();
                cur_level.push_back(cur->val);
                for (int j = 0; j < cur->children.size(); j++){
                    if (cur->children[j]) nodeque.push(cur->children[j]);
                }
            }
            result.push_back(cur_level);
        } 
        return result;
    }
};