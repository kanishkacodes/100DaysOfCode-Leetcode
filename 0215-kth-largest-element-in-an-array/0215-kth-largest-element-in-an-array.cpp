class Solution
{
    public:
        int findKthLargest(vector<int> &nums, int k)
        {
//             map<int, int> m;
//             for (int i = 0; i < nums.size(); ++i)
//             {
//                 m[nums[i]]++;
//             }

//             for (auto it = m.begin(); it != m.end(); it++)
//             {
//                 it->second = 1;
//             }

//             nums.clear();

//             for (auto ct: m)
//             {
//                 int element = ct.first;
//                 int count = ct.second;
//                 for (int i = 0; i < count; ++i)
//                 {
//                     nums.push_back(element);
//                 }
//             }
//             int n = nums.size();
//             return nums[n - k];
            
            sort(nums.begin(),nums.end());
            int n = nums.size();
            return nums[n-k];
        }
};