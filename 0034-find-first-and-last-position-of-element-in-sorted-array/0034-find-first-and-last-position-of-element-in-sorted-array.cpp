class Solution {
public:
int rightmostelement(vector<int>&nums,int target){
    int n = nums.size();
    int low = 0; // Corrected initialization
    int high = n - 1; // Corrected initialization
    int rightmost= -1;
    
    while (low <= high){
        
        int mid = (low+high)/2;
        
        if (nums[mid] ==  target){
            rightmost = mid;
            low = mid + 1; // Correction made here, moving towards right
        }
        else if (nums[mid] < target){ // Corrected condition
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }
    
    return rightmost;
    
}
int leftmostelement(vector<int>&nums,int target){
    int n = nums.size();
    int low = 0; // Corrected initialization
    int high = n - 1; // Corrected initialization
    int leftmost = -1;
    
    while(low <= high){
        
        int mid =(low+high)/2;
        
        if (nums[mid] == target){
            leftmost = mid;
            high = mid - 1; // Correction made here, moving towards left
        }
        else if (nums[mid] < target){ // Corrected condition
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }
    
    return leftmost;
}

    vector<int> searchRange(vector<int>& nums, int target) {
      
        int left = leftmostelement(nums,target);
        int right = rightmostelement(nums,target);
        
        return {left,right};
        
    }
};