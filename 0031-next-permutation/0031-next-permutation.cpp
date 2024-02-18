class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        
        int index = -1 ;
        int n = nums.size();
        
        
        //First find the dip (like what is smaller after a big number) and store the dip in index 
        
        
        for (int i = n-2 ; i >= 0 ; i--){
            
            if (nums[i]<nums[i+1]){
                
                index = i;
                break;
            }
            
            
        }
        
        //if there is no dip
        if ( index == -1 )  {
                
                reverse(nums.begin(), nums.end());
            }
        
        // or if it has a dip
        else{
         
        //swap the dip with the next smallest number
        for (int i = n-1 ; i > index ; i--){
            
            if (nums[i] > nums[index]){
                
                swap(nums[i],nums[index]);
                break;
            }
        }
        
        // at the end reverse the rmaining array it will be sorted
        reverse(nums.begin()+index+1, nums.end());
            
        }
        
    }
};