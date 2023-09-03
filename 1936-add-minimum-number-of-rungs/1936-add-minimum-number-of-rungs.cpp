class Solution {
public:
     int addRungs(vector<int>& A, int dist) {
        int pre = 0, res = 0;
        for (int a: A) {
            res += (a - pre - 1) / dist;
            pre = a;
        }
        return res;
    }
};