class Solution {
public:
    unordered_map<string , int> mp;
    int dfs(string s1, string s2){
        if (s1==s2){
            return 1;
        }
        if (s1.size()!=s2.size()){
            return 0;
        }
        string key = s1+"-"+s2;
        if (mp.find(key)!=mp.end()){
            return mp[key];
        }
         
        int res = 0;
        int n = s1.size();
        for (int i=1; i<n; i++){
            // s1 -> 0 to i (part 1) : x1
            // s2 -> n-i to i (part 2) : y2
            
            // s1 -> i to n-i (part 2) : x2
            // s2 -> 0 to i (part 1): y1
            
            // before 
            // x1 : s1
            // y1 : s2
            
            // x2 : s1
            // y2 : s2
            
            // x1 + x2 , y1 + y2
            //  abc(x1) + de(x2), de(y1) + abc(y2)
            // if scramble
            // de + abc should be equal to s2
            // so abc(x1) == abc(y2)
            // de(x2) == de(y1)
            
            
            // Two options
            // swap and match 
            int swap = dfs(s1.substr(0,i), s2.substr(n-i, i)) && dfs(s1.substr(i, n-i), s2.substr(0, n-i));
            
            // keep as it is-> don't do anything
            int notswap = dfs(s1.substr(0,i), s2.substr(0, i)) && dfs(s1.substr(i, n-i), s2.substr(i, n-i));
            
            if (swap || notswap){
                res = true;
                break; // no need to check for other split
            } 
            
        }
        return mp[key] = res;
   
    }
    bool isScramble(string s1, string s2) {        
        return dfs(s1, s2);       
    }
};