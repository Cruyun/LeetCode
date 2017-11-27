class Solution {
public:
    bool isValid(string s) {
        stack<char> c;
        int flag = 1;
        
        for (int i = 0; i < s.length() && flag; i++) {
            switch(s[i]) {
                case '(':
                case '[':
                case '{': {
                    c.push(s[i]);
                    break;
                }
                case ')': {
                    if (!c.empty() && c.top() == '(') {
                        c.pop();
                    } else
                        flag = 0;
                    break;
                }
                case ']': {
                    if (!c.empty() && c.top() == '[') {
                        c.pop();
                    } else
                        flag = 0;
                    break;
                }
                case '}': {
                    if (!c.empty() && c.top() == '{') {
                        c.pop();
                    } else
                        flag = 0;
                    break;
                }
            }
        }
        if (c.empty() && flag)
            return true;
        else
            return false;
    }
};