class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
     int n=nums.size();
       vector<int>v;
       unordered_map<int,int>m;
        for(int i=0; i<n; i++){
         
         m[nums[i]]++;
         
         if(m[nums[i]]>n/3){
            
             v.push_back(nums[i]);
             
             m[nums[i]]=-1;  
         }
     }  
     
        return v;
    }
};