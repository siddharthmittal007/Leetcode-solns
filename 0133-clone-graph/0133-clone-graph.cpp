/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* dfs(Node *node,vector<Node*> &v){
        // Node already created
        if(v[node->val]!=nullptr)return(v[node->val]);

        // Create node
        Node *newNode=new Node(node->val);
        v[node->val]=newNode;
        // Set neighbours
        for(Node* it : node->neighbors){
            newNode->neighbors.push_back(dfs(it,v));
        }
        // Return pointer
        return(newNode);
    }
    
    Node* cloneGraph(Node *node) {
        // Trivial Case
        if(node==nullptr)return(nullptr);
        
        // Ponters to nodes of each value
        vector<Node*> v(101,nullptr);
        // DFS cloning
        Node *root=dfs(node,v);
        return(root);
    }
};