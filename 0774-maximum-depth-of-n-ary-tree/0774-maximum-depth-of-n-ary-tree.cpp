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
    int maxDepth(Node* root) {
      if (root == nullptr) return 0;
        queue<Node*> nodeque;
        nodeque.push(root);
        int depth = 0;
        while (! nodeque.empty()){
            int size = nodeque.size();
            depth++;
            for (int i = 0; i < size; i++){
                Node* cur = nodeque.front();
                nodeque.pop();
                for (auto child : cur->children)
                    nodeque.push(child);
            }
        }
        return depth;  
    }
};