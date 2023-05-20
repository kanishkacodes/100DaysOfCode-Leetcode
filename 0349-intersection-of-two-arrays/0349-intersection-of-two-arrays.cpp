class Solution {
public:
    
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int> st1, st2;
        vector<int> ans;

        for(auto val: nums1) // Store nums1 elements to set1
            st1.insert(val);

        for(auto val: nums2) // Store nums2 elements to set2
            st2.insert(val);

        for(auto val: st1) // Store intersection elements to ans
            if(st2.count(val))
                ans.push_back(val);

        return ans; 
    }
};