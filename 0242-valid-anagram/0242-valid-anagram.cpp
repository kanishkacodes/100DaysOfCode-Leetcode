class Solution {

public:
    bool isAnagram(string s, string t) {
        sort(s.begin(),s.end());
        sort(t.begin(),t.end());
        int f=1;
        for(int i=0;i<s.size();i++){
            if(s[i]!=t[i]){f=0;break;}
            }
            if(f==0 || s.size()!=t.size()) return 0;
            else return 1;
    }
};