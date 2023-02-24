class Solution {
public:

    int maxArea(vector<int>& height) {
       int i = 0, j = height.size()-1;
       int bigger_volume = 0;

       while(i<j){
           int sml_height = 0;
           
           if(height[i] >= height[j]){
                sml_height =  height[j];
            }
            else{
                sml_height = height[i];
            }

            int volume = (j-i) * sml_height;

           if(volume > bigger_volume){
               bigger_volume = volume;
           }
           if(height[j] > height[i]){
               i++;
           }
           else{
               j--;
           }
       }

        return bigger_volume;


        
    }
};