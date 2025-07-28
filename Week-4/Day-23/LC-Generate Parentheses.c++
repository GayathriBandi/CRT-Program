Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.
Example 1:
Input: n = 3
Output: ["((()))","(()())","(())()","()(())","()()()"]
Example 2:
Input: n = 1
Output: ["()"]
Constraints:
1 <= n <= 8

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;

        function<void(int, int, string)> depthFirstSearch = [&](int leftCount, int rightCount, string current) {
            if (leftCount > n || rightCount > n || leftCount < rightCount) return;
            if (leftCount == n && rightCount == n) {
                result.push_back(current);
                return;
            }
            depthFirstSearch(leftCount + 1, rightCount, current + "(");
            depthFirstSearch(leftCount, rightCount + 1, current + ")");
        };

        depthFirstSearch(0, 0, "");
        return result;
    }
};
