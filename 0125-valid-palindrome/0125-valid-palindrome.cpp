class Solution {
public:
    bool isPalindrome(string s) {
        int l=0,h=s.size()-1;
        transform(s.begin(),s.end(),s.begin(),::tolower);
        while(l<=h){
            if(!isalnum(s[l]))
            l++;
            else if(!isalnum(s[h]))
            h--;
            else if((s[l])!=(s[h]))
            return 0;
            else{
                l++; h--;
            }
            
        }
        return 1;
        
        
    }
};