class Solution {
public:
    bool canChoose(vector<vector<int>>& groups, vector<int>& nums)
    {
        int numsIndex = 0;
        int groupsIndex = 0;
        
        while (numsIndex < nums.size() && groupsIndex < groups.size())
        {
			// Try to match as many members of the current group as possible
            int matchCount = 0;
            while (numsIndex + matchCount < nums.size() &&
                   matchCount < groups[groupsIndex].size() &&
                   nums[numsIndex + matchCount] == groups[groupsIndex][matchCount])
                ++matchCount;
            
			// Did we match the entire current group?
            if (matchCount == groups[groupsIndex].size())
            {
				// the group was matched
                ++groupsIndex;
				
				// since there must not be overlap between groups
				// we must match the next group at next element in nums
                numsIndex += matchCount;
            }
            else
            {
				// unsucessful in matching all elements of current group
				// retry matching the group from start at next element in nums
                ++numsIndex;
            }
        }
        
        return groupsIndex == groups.size();
    }
};