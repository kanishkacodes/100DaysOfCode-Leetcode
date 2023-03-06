//https://leetcode.com/problems/intersection-of-two-arrays-ii/

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        map<int,int>mp1;
        map<int,int>mp2;
        vector<int>ans;
        for(auto val: nums1){
            mp1[val]++;
        }
        for(auto val: nums2){
            mp2[val]++;
        }
        for(auto &value :mp1){
            auto itr=mp2.find(value.first);
            if(itr!=mp2.end()){
                int temp=min(value.second,itr->second);
                while(temp!=0){
                 ans.push_back(value.first);
                 temp--;
                }
            }
        }
        return ans;
    }
};