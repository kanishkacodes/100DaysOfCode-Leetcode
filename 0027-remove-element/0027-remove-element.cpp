class Solution
{
    public:
        int removeElement(vector<int> &nums, int val)
        {
            unordered_map<int, int> m;
            for (int i = 0; i < nums.size(); ++i)
            {
                m[nums[i]]++;
            }
            for (auto it = m.begin(); it != m.end(); )
            {
                if (it->first == val)
                {
                    it = m.erase(it);
                }
                else
                {
                    ++it;
                }
            }

            nums.clear();  // clear the original vector

            for (auto ct: m)
            {
                int element = ct.first;
                int count = ct.second;
                for (int i = 0; i < count; i++)
                {
                    nums.push_back(element);
                }
            }
            return nums.size();
        }
};
