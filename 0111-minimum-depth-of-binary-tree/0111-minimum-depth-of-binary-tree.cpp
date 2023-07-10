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
    int minDepthDfs(TreeNode* root)
    {
        int left = INT_MAX;
        int right = INT_MAX;

        if(root->left != nullptr)
        {
            left = 1 + minDepthDfs(root->left);
        }
        
        if(root->right != nullptr)
        {
            right = 1 + minDepthDfs(root->right);
        }

        //No further nodes, which means we know this is the leaf node
        if(left == INT_MAX && right == INT_MAX)
        {
            return 1;
        }

        return std::min(left, right);
    }
    int minDepth(TreeNode* root) {
        
        if(root == nullptr)
        {
            return 0;
        }

        int returnVal = minDepthDfs(root);

        return returnVal;
    }
};