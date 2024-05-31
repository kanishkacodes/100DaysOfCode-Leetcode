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
    
    bool isBalanced(TreeNode* root) {
        return checkBalance(root).first;
    }
    

    // This function returns a pair, where:
    // - The first element is a boolean indicating whether the subtree is balanced.
    // - The second element is the height of the subtree.
    pair<bool, int> checkBalance(TreeNode* node) {
        
        if (node == NULL) {
            return {true, 0};
        }
        
        auto left = checkBalance(node->left);
        auto right = checkBalance(node->right);
        
        
        bool balanced = left.first && right.first && abs(left.second - right.second) <= 1;
        
        int height = 1 + max(left.second, right.second);
        
        return {balanced, height};
    }
};
