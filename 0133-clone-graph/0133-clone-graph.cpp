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
    Node* cloneGraph(Node* node) {
        
        if(node == nullptr)
        {
            return nullptr;
        }

        std::unordered_set<int> visited;
        std::array<std::vector<int>, 101> adjacencyList;
        std::array<Node*, 101> nodeArr;

        std::queue<Node*> nodeQ;
        nodeQ.emplace(node);
        visited.emplace(node->val);
        
        while(nodeQ.empty() == false)
        {
            Node* newNode = nodeQ.front();
            nodeQ.pop();
            nodeArr[newNode->val] = new Node(newNode->val);

            for(int i = 0; i < newNode->neighbors.size(); i++)
            {
                int neighborVal = newNode->neighbors[i]->val;
                adjacencyList[newNode->val].emplace_back(neighborVal);

                if(visited.count(neighborVal) == 0)
                {
                    nodeQ.emplace(newNode->neighbors[i]);
                    visited.emplace(neighborVal);
                }
            }
        }
        for(int i = 1; i < adjacencyList.size(); i++)
        {
            for(const int neighbor: adjacencyList[i])
            {
                nodeArr[i]->neighbors.emplace_back(nodeArr[neighbor]);
            }
        }

        return nodeArr[1];
    }
};