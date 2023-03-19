class Solution {
public:
    void chk(int l,int r,string &s,int &max,string &ans){
        while(l>=0 && r<s.size() && s[l]==s[r]){
            l--;
            r++;
        }
        l++;
        r--;

        int a=r-l+1;
        if(a>max){
            ans=s.substr(l,a);
            max=a;
        }
    }

    string longestPalindrome(string s) {
        int n=s.size();
        int max=0;
        string ans="";

      

        for(int i=0;i<n;i++){

            chk(i,i,s,max,ans);
            if(i==n-1){
                break;
            }
            chk(i,i+1,s,max,ans);

            if(max==n){
                return s;
            }
        }
        return ans;
    }
};
