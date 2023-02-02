class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int, int> m;
    for (int i = 0; i < nums.size(); ++i)
    {
        m[nums[i]]++;
    }

    vector<int> nums2;
    for (auto &pr : m)
    {
        nums2.push_back(pr.second);
    }

    int max = *(max_element(nums2.begin(), nums2.end()));
    for (auto &co : m)
    {
        if (co.second == max)
        {
            return co.first;
        }
    }

    return 0;
         
    }
};