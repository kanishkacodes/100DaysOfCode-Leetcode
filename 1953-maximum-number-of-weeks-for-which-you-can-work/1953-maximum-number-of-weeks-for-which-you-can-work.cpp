class Solution {
public:
    long long numberOfWeeks(vector<int>& milestones) {
        int mx = *max_element(milestones.begin(), milestones.end());
        long long sum = 0;
        for(int i = 0; i < milestones.size(); i++) {
            sum += (long long) milestones[i];
        }
        long long rest = sum - (long long)mx;
        return min({rest * 2 + 1, sum});
    }
};