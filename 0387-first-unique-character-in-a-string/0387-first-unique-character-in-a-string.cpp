class Solution {
public:
    int firstUniqChar(string s) {
        
    for (int i = 0; i < s.size(); i++)
    {
        bool found = false;
        if (s[i] == '@')
        {
            found=true;
            continue;
        }
        for (int j = i + 1; j < s.size(); j++)
        {
            if (s[i] == s[j])
            {
                found = true;
                s[j] = '@';
            }
        }
        if (found == false)
        {
            return i;
        }
    }
    return -1;
    

    }
};