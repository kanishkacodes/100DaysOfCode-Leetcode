//Aggressive Cows variation

class Solution {
public:
    int maxDistance(vector<int>& position, int m) {
        
        sort(position.begin(),position.end());
        
        int n = position.size();
        
        int low = 1;
        int high = position[n-1] - position[0];
        
        while (low <= high){
            
           int  mid = (low+high)/2;
            
            if (canweplace(position,mid,m) == true){
                low = mid+1;
            }
            
            else{
                
                high = mid-1;
            }
            
            
        }
        
        return high;
        
    }
    
    
    bool canweplace(vector<int>&v, int distance , int balls){
        
       int totalballs = 1;
       int lastballposition = v[0];
        
        for (int i = 0 ; i < v.size() ; i++){
            
            if(v[i]-lastballposition >= distance){
                totalballs++;
                lastballposition =v[i];
            }
            
            if (totalballs >= balls){
                
                return true;
            }
            
        }
        
        return false;
        
    }
};