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
    TreeNode* bstFromPreorder(vector<int>& A) {
        int i = 0;
        return build(A, i, INT_MAX);
    }

    // Recursive helper function to build a binary search tree from the preorder traversal array.
    // 'i' is the index of the current element in the array.
    // 'bound' is the upper bound for the current subtree (values should be less than 'bound').
    TreeNode* build(vector<int>& A, int& i, int bound) {
        // If all elements have been processed or the current element is greater than the bound,
        // return NULL indicating an empty subtree.
        if (i >= A.size() || A[i] > bound) {
            return NULL;
        }

        // Create a new node with the current element as the value.
        TreeNode* root = new TreeNode(A[i++]);

        // Recursively build the left subtree with the elements that are less than the current node's value.
        // The upper bound for the left subtree is the current node's value.
        root->left = build(A, i, root->val);

        // Recursively build the right subtree with the elements that are greater than the current node's value.
        // The upper bound for the right subtree is the same as the parent's upper bound.
        root->right = build(A, i, bound);

        // Return the constructed root of the subtree.
        return root;
    }
};
