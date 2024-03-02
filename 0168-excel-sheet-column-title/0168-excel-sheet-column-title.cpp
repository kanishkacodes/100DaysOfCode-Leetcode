// Initial value of n is 30.
// In the while loop:
// n is decremented to 29.
// curr is set to 29 % 26, which is 3 ('C').
// n is updated to 29 / 26, which is 1.
// 'C' is pushed back to the string ans.
// In the next iteration:
// n is decremented to 0.
// curr is set to 0 % 26, which is 0 ('A').
// n is updated to 0 / 26, which is 0.
// 'A' is pushed back to the string ans.
// The loop exits as n is now 0.
// The string ans is reversed, so the final result is "AC".
// Therefore, if n = 30, the output of convertToTitle(n) will be "AC".


// Since the characters are extracted from the rightmost digit of the given number n, the result will be reversed when compared to the order in which the characters would appear if you read the digits from left to right.

// curr + 'A': Adding 'A' to curr converts the index to the ASCII value of the corresponding uppercase letter. For example, if curr is 0, then curr + 'A' is 'A'; if curr is 1, then curr + 'A' is 'B', and so on.


class Solution {
public:
    string convertToTitle(int n) {
        
        string ans ;
        while ( n > 0 ){
            n--;
            int curr = n % 26;
            n = n / 26;
            ans.push_back(curr + 'A');
            
        }
        
        reverse(ans.begin(),ans.end());
        return ans;
    }
};