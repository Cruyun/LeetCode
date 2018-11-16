class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        bool hash[1001];
        for (int j = 0; j < 1001; j++) {
            hash[j] = false;
        }
        hash[0] = true;
        queue<int> q;
        q.push(0);
        int count = 1;
        
        while(!q.empty()) {
            for (int i = 0; i < rooms[q.front()].size(); i++) {
                if (!hash[rooms[q.front()][i]]) {
                    q.push(rooms[q.front()][i]);
                    count++;
                    hash[rooms[q.front()][i]] = true;
                }
            }
            q.pop();
        }

        return count != rooms.size() ? false : true;
    }
};