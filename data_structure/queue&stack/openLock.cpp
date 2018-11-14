class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        bool visited[10000] = {0};
        for (auto &s : deadends) {
            visited[stoi(s)] = true;
        }
        int res = 0;
        int t = stoi(target);
        
        queue<int> q;
        q.push(0);
        
        while(!q.empty()) {
            int n = q.size();
            for (int i = 0; i < n; i++) {
                auto s = q.front();
                if (s == t) {
                    return res;
                }
                q.pop();
                if (visited[s]) {
                    continue;
                }
                visited[s] = true;
                for (int j = 1; j <= 1000; j *= 10) {
                    q.push(s + ((s / j + 1) % 10 - s / j % 10) * j);
                    q.push(s + ((s / j + 9) % 10 - s / j % 10) * j);
                }
            }
            res++;
        }
        return -1;
    }
};