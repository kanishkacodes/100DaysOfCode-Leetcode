class Solution {
public:
    string triangleType(vector<int>& n) {
    sort(begin(n), end(n));
    if (n[2] >= n[0] + n[1])
        return "none";
    return n[0] == n[2] ? "equilateral" : n[0] == n[1] || n[1] == n[2] ? "isosceles" : "scalene";
}
};