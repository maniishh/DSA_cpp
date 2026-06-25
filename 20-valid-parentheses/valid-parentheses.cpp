class Solution {
public:
    bool isValid(string s) {
        stack<char> stack;
        unordered_map<char, char> matchingBrackets = {
            {')', '('}, {'}', '{'}, {']', '['}};

        for (char c : s) {
            if (matchingBrackets.find(c) != matchingBrackets.end()) {

                if (!stack.empty() && stack.top() == matchingBrackets[c]) {
                    stack.pop();
                } else {
                    return false;
                }
            } else {

                stack.push(c);
            }
        }

        return stack.empty();
    }
};