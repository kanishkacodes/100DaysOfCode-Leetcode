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
    TreeNode* flattenHelper(TreeNode* node) {
        if (!node->left && !node->right) {
            return node;
        }

        TreeNode* leftTail = nullptr;
        TreeNode* rightTail = nullptr;

        if (node->left) {
            leftTail = flattenHelper(node->left);
        }

        if (node->right) {
            rightTail = flattenHelper(node->right);
        }

        if (leftTail) {
            leftTail->right = node->right;
            node->right = node->left;
            node->left = nullptr;
        }

        return rightTail ? rightTail : leftTail;
    }
};

