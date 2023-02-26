class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char,int> mapping={ { 'I' , 1 },
                                   { 'V' , 5 },
                                   { 'X' , 10 },
                                   { 'L' , 50 },
                                   { 'C' , 100 },
                                   { 'D' , 500 },
                                   { 'M' , 1000 } };

        int sum=0;
        for(int i=0;i<s.size();i++)
        {
            if(mapping[s[i]]>=mapping[s[i+1]])
            {
                sum+=mapping[s[i]];
            }
            else
            {
                sum+=mapping[s[i+1]]-mapping[s[i]];
                i++;
            }
        }

        return sum;
    }
};