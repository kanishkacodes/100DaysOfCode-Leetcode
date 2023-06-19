class Solution {
public:
    string reverseWords(string s) {
        vector<string>v;
        stringstream str(s);
        string word;
        
        while(str>>word) {
            v.push_back(word);
        }
        reverse(v.begin(), v.end());
        
        string ans;
        for(auto it :v) {
            ans = ans + " " + it;
        }
        ans.erase(0, 1); 
        return ans;
    }
};