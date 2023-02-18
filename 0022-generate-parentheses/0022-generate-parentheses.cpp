class Solution {
public:

    void solve(vector<string> &ans, int n , int open , int close,string output){
        if(output.length() == 2*n){
            ans.push_back(output);
            return;
        }
        if(open<n) solve(ans,n,open+1,close,output+"(");

        if(close<open) solve(ans,n,open,close+1,output+")");
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        solve(ans,n,0,0,"");
        return ans;
    }
};