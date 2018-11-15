class Solution {
public:
    bool isValid(string s) {
         vector<char> temp;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
                temp.push_back(s[i]);
            } 
            if (s[i] == '}' || s[i] == ']' || s[i] == ')') {
                if (temp.empty()) {
                    return false;
                }
                if ((temp.back() == '(' && s[i] == ')') || (temp.back() == '[' && s[i] == ']') || (temp.back() == '{' && s[i] == '}')) {
                temp.pop_back();
            } else {
                    return false;
                }
            }
        }
        if (!temp.empty()) return false;
        return true;
    }
};