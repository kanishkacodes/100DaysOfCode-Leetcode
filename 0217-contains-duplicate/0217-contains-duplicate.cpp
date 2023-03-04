//https://leetcode.com/problems/contains-duplicate/

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
      unordered_map<int, int> m;
      for (int i = 0; i < nums.size(); ++i)
      {
         m[nums[i]]++;
      }
      for( auto &it : m){
         if (it.second > 1 ){
             return true;
         } 
      }
        return false; 
    }
};