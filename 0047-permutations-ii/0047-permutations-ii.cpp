class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        
        vector<vector<int>> ans;
        vector<int> emp;
        vector<bool> visited(nums.size(), false);
        sort(nums.begin(), nums.end());
        helper(nums, emp, ans,visited );
        
        return ans;
    }
    
    void helper(vector<int>& nums, vector<int>& emp, vector<vector<int>>& ans, vector<bool>&visited) {
        
        
        if (emp.size() == nums.size()) {
            
            ans.push_back(emp);
            return;
            
        }
        
        

        for (int i = 0; i < nums.size(); i++) {
            
            if (visited[i] || (i > 0 && nums[i] == nums[i - 1] && !visited[i - 1])) {
                
                continue;
            }
                
                visited[i] = true;
                emp.push_back(nums[i]);
                helper(nums, emp, ans,visited);
                emp.pop_back();
                visited[i] = false;
            }
        }
    
};

















































// class Solution {
// public:
//     void backtrack(int index, vector<int>& nums, vector<vector<int>>& ans) {
//         if (index == nums.size()) {
//             ans.push_back(nums);
            
//         }
//         else{

//         unordered_set<int> used; // Track used elements to avoid duplicates

//         for (int i = index; i < nums.size(); i++) {
//             // Check if the current element has already been used at this index
//             if (used.find(nums[i]) != used.end()) {
//                 continue;
//             }

//             // Add the current element to the set of used elements
//             used.insert(nums[i]);

//             swap(nums[index], nums[i]);
//             backtrack(index + 1, nums, ans);
//             swap(nums[index], nums[i]);
//         }
//         }
//     }

//     vector<vector<int>> permuteUnique(vector<int>& nums) {
//         vector<vector<int>> ans;
//         backtrack(0, nums, ans);
//         return ans;
//     }
// };