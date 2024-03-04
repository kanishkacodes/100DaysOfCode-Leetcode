class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> countRemainders(k, 0);

        for (int i = 0; i < n; i++) {
            int remainder = (arr[i] % k + k) % k;
            countRemainders[remainder]++;
        }

        if (countRemainders[0] % 2 != 0) {
            return false; // There should be an even number of elements with remainder 0
        }

        for (int i = 1; i <= k / 2; i++) {
            if (countRemainders[i] != countRemainders[k - i]) {
                return false; // Pairs with complementary remainders should have the same count
            }
        }

        return true;
    }
};
