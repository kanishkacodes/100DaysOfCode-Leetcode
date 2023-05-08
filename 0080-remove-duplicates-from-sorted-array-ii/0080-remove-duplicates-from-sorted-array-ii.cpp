class Solution
{
    public:
        int removeDuplicates(vector<int> &nums)
        {
           	// first we took a map because answer is in sorted form and converted the vector into map.
            map<int, int> m;

            for (int i = 0; i < nums.size(); ++i)
            {
                m[nums[i]]++;
            }
           	// main logic: we put the count of value two always because we have to such that each unique element appears at most twice.       
            for (auto ct = m.begin(); ct != m.end();)
            {
                if (ct->second > 2)
                {
                    ct->second = 2;
                }
                else
                {
                    ++ct;
                }
            }
           	// cleared the privious vector.
            nums.clear();
           	
            // converted map to vector.     
            for (auto it: m)
            {
                int element = it.first;
                int count = it.second;
                for (int i = 0; i < count; ++i)
                {
                    nums.push_back(element);
                }
            }
            return nums.size();
        }
};