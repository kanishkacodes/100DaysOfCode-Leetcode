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
    void flatten(TreeNode* root) {
        if (root) {
            flattenHelper(root);
        }
    }

private:
    TreeNode* flattenHelper(TreeNode* currentNode) {
        // Base case: If the currentNode has no left and right children, return itself as the tail.
        if (!currentNode->left && !currentNode->right) {
            return currentNode;
        }

        TreeNode* leftSubtreeTail = nullptr;  // Tail of the flattened left subtree.
        TreeNode* rightSubtreeTail = nullptr; // Tail of the flattened right subtree.

        // Recursively flatten the left subtree and get its tail.
        if (currentNode->left) {
            leftSubtreeTail = flattenHelper(currentNode->left);
        }

        // Recursively flatten the right subtree and get its tail.
        if (currentNode->right) {
            rightSubtreeTail = flattenHelper(currentNode->right);
        }

        // If there is a flattened left subtree, attach it to the right of the currentNode.
        if (leftSubtreeTail) {
            leftSubtreeTail->right = currentNode->right;
            currentNode->right = currentNode->left;
            currentNode->left = nullptr;
        }

        // Return the tail of the right subtree if it exists, or the tail of the left subtree otherwise.
        return rightSubtreeTail ? rightSubtreeTail : leftSubtreeTail;
    }
};



