/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        queue<Node*> nodeque;
        if (root != nullptr)
            nodeque.push(root);
        while (!nodeque.empty()) {
            int size = nodeque.size();
            Node* prev = new Node();
            for (int i = 0; i < size; i++) {
                Node* cur = nodeque.front();
                nodeque.pop();
                prev->next = cur;
                prev = prev->next;
                if (cur->left)
                    nodeque.push(cur->left);
                if (cur->right)
                    nodeque.push(cur->right);
            }
            prev->next = nullptr;
        }
        return root;
    }
};