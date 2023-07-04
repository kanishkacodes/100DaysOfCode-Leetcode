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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == NULL){
            return NULL;
        }

        if (root->val == key){
            return arrangement(root);
        }

        TreeNode* dummy = root; // Changed from '==' to '=' for assignment

        while(root != NULL){
            if (root->val > key){
                if(root->left != NULL && root->left->val == key){
                    root->left = arrangement(root->left);
                    break;
                } else {
                    root = root->left;
                }
            }
            else{
                if(root->right != NULL && root->right->val == key){
                    root->right = arrangement(root->right);
                    break;
                }
                else{
                    root = root->right;
                }
            }
        }

        return dummy;
    }

    TreeNode* arrangement(TreeNode* root) {
        if (root ->left == NULL){
            return root ->right;
        }
        
        else if (root->right == NULL){
            return root->left;
        }
        
        TreeNode* rightChild = root->right;
        TreeNode* lastRight = findLastRight(root->left); // Fixed function name
        lastRight->right = rightChild;
        return root->left;
    }

    TreeNode* findLastRight(TreeNode* root) { // Renamed function to 'findLastRight'
        if(root->right == NULL){
            return root;
        }

        return findLastRight(root->right);
    }
};
