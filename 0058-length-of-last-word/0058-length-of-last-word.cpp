class Solution
{
public:
    int lengthOfLastWord(string s)
    {
        int count = 0;
        for (int c = s.size() - 1; c >= 0; c--)
        {
            if (s[c] != ' ')
            {
                count++;
            }
            // if we already found a word and then encounter
            // a space that means the word is over.
            else if (count != 0 && s[c] == ' ')
            {
                return count;
            }
        }
        return count;
    }
};