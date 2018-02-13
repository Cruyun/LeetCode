class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1)
            return s;
        
        int col = 0;
        int len = s.size();
        bool flag = true;
        string arr[numRows];
        int i;
        
        for (i = 0; i < numRows; i++)
            arr[i] = "";
        
        for (i = 0; i < len; i++) {
            arr[col] += s[i];
            
            if (col == 0) {
                flag = true;
            } else if (col == numRows - 1) {
                flag = false;
            }
            
            (flag == true) ? col++ : col--;
        }
        
        string result = "";
        for (i = 0; i < numRows; i++) {
            result += arr[i];
        }
        
        return result;
    }
};