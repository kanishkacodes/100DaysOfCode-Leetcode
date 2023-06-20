//{ Driver Code Starts
// C++ program to evaluate value of a postfix expression

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends



class Solution {
public:
    // Function to evaluate a postfix expression.
    int evaluatePostfix(string S) {
        stack<int> operands;

        for (char c : S) {
            if (isdigit(c)) {
                int num = c - '0';
                operands.push(num);
            } else {
                int operand2 = operands.top();
                operands.pop();
                int operand1 = operands.top();
                operands.pop();
                int result = performOperation(c, operand1, operand2);
                operands.push(result);
            }
        }

        return operands.top();
    }

    int performOperation(char op, int operand1, int operand2) {
        if (op == '*') {
            return operand1 * operand2;
        } else if (op == '/') {
            return operand1 / operand2;
        } else if (op == '+') {
            return operand1 + operand2;
        } else if (op == '-') {
            return operand1 - operand2;
        } else {
            return 0;
        }
    }
};


//{ Driver Code Starts.

// Driver program to test above functions
int main()
{
    int t;
    cin>>t;
    cin.ignore(INT_MAX, '\n');
    while(t--)
    {
        string S;
        cin>>S;
        Solution obj;
    
    cout<<obj.evaluatePostfix(S)<<endl;
    }
    return 0;
}

// } Driver Code Ends