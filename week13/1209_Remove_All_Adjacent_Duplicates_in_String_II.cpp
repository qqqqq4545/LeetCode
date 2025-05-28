class Solution {
public:
    string removeDuplicates(string s, int k) {
        vector<pair<char, int>> stack;
        
        for (char c : s) {
            if (stack.empty() || stack.back().first != c) {
                stack.push_back({c, 1});
            } else {
                stack.back().second++;
                
                if (stack.back().second == k) {
                    stack.pop_back();
                }
            }
        }
        
        string result = "";
        for (auto& p : stack) {
            result += string(p.second, p.first);
        }
        
        return result;
    }
};
