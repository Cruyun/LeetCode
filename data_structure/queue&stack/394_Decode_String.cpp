class Solution {
public:
    string decodeString(string s) {
      string res = "";
      stack<char> temp;

      for (int i = 0; i < s.length(); i++) {
        // 数字 字母入栈
        if (isalpha(s[i]) || isdigit(s[i]) || s[i] == '['){
          temp.push(s[i]);
        }
        if (s[i] == ']') {
          string ss = "";
          while(!temp.empty() && isalpha(temp.top())) {
            ss = temp.top() + ss;
            temp.pop();
          }
          
          if (temp.top() == '[') temp.pop();
          string num = "";
          while(!temp.empty() && isdigit(temp.top())) {
            num = temp.top() + num;
            temp.pop();
          }
          int n = stoi(num);
          for (int j = 1; j <= n; j++) {
            for (int k = 0; k < ss.length(); k++) {
              temp.push(ss[k]);
            }
          }
        }
      }
      while (!temp.empty()) {
        res = temp.top() + res;
        temp.pop();
      }
      return res;
    }
};