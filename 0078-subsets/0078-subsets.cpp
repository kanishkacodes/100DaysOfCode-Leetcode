class Solution
{
    public:
        vector<vector < int>> ans;

    void backtrack(int index, vector<int> &v, vector<int> &nums)
    {

        if (index == nums.size())
        {
            ans.push_back(v);
        }
        else
        {
            v.push_back(nums[index]);
            backtrack(index + 1, v, nums);

            v.pop_back();
            backtrack(index + 1, v, nums);
        }
    }

    vector<vector < int>> subsets(vector<int> &nums)
    {
        vector<int> v;
        backtrack(0, v, nums);
        return ans;
    }
};