#include <queue>

class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        
        int maxSum = root->val;
        int maxLevel = 1;
        
        std::queue<TreeNode*> q;
        q.push(root);
        int level = 1;
        
        while (!q.empty()) {
            int levelSum = 0;
            int levelSize = q.size();
            
            for (int i = 0; i < levelSize; i++) {
                TreeNode* node = q.front();
                q.pop();
                
                levelSum += node->val;
                
                if (node->left) {
                    q.push(node->left);
                }
                if (node->right) {
                    q.push(node->right);
                }
            }
            
            if (levelSum > maxSum) {
                maxSum = levelSum;
                maxLevel = level;
            }
            
            level++;
        }
        
        return maxLevel;
    }
};
