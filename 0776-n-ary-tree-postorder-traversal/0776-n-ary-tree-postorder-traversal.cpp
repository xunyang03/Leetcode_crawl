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
    void recurse(Node* node, vector<int>& vec){
        if (node == nullptr) return;
        for (auto child : node->children){
            recurse(child, vec);
        }
        vec.push_back(node->val);        
    }
    
    vector<int> postorder(Node* root) {
        vector<int> result;
        recurse(root, result);
        return result;
    }
};