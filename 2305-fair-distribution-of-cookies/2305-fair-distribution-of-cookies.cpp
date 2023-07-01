

class Solution {
public:
    int ans = INT_MAX;

    void helper(const std::vector<int>& cookies, int start, int k, std::vector<int>& temp) {
        if (start == cookies.size()) {
            int max = 0;
            for (int c : temp)
                max = std::max(max, c);
            ans = std::min(ans, max);
            return;
        }
        for (int i = 0; i < k; i++) {
            temp[i] += cookies[start];
            helper(cookies, start + 1, k, temp);
            temp[i] -= cookies[start];
        }
    }

    int distributeCookies(const std::vector<int>& cookies, int k) {
        std::vector<int> temp(k, 0);
        helper(cookies, 0, k, temp);
        return ans;
    }
};
