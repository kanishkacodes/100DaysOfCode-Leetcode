class Solution {
public:
    int minimumSum(int num) {
        
        string s;
        while(num)
        {
                int deg=num%10;
                num=num/10;
                s+=(deg+'0');
            
            
        }
                
         
                
            sort(s.begin(),s.end());
                
            string s1(1,s[0]);
            string s2(1,s[1]);
            s1+=s[3],s2+=s[2];
            
            int num1=stoi(s1);
            int num2=stoi(s2);
            return num1+num2;
                    
     }
};