class Solution
{
    public:
        int removeElement(vector<int> &nums, int val)
        {
           	//Inserting the value into unordered map

            unordered_map<int, int> m;
            for (int i = 0; i < nums.size(); ++i)
            {
                m[nums[i]]++;
            }

           	// Checking if the map contains the value that is given and deleting it 

            for (auto it = m.begin(); it != m.end();)
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
           	// clear the original vector
            
            nums.clear();

           	//Again converthing the map back to the vector

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