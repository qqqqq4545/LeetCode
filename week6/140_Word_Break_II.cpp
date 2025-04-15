class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        unordered_map<string, vector<string>> memo;
        return wordBreakHelper(s, dict, memo);
    }
    
    vector<string> wordBreakHelper(string s, unordered_set<string>& dict, unordered_map<string, vector<string>>& memo) {
        // already computed
        if (memo.find(s) != memo.end()) {
            return memo[s];
        }
        
        vector<string> result;
        
        // If the entire string is a word, add it to the result
        if (dict.find(s) != dict.end()) {
            result.push_back(s);
        }
        
        for (int i = 1; i < s.length(); i++) {
            string prefix = s.substr(0, i);
            
            // If the prefix is a word in the dictionary
            if (dict.find(prefix) != dict.end()) {
                // Recursively find all ways to break the remaining part
                string remaining = s.substr(i);
                vector<string> subResult = wordBreakHelper(remaining, dict, memo);
                
                // Combine prefix with each way to break the remaining
                for (const string& sub : subResult) {
                    result.push_back(prefix + " " + sub);
                }
            }
        }
        
        memo[s] = result;
        return result;
    }
};
