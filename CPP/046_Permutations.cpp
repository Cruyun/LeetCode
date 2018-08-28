class Solution {
public:
    void backTracking(vector<int>& nums, vector<bool>& visited, vector<vector<int>>& result, vector<int> current) {
      if (current.size() == nums.size()) {
        result.push_back(current);
        return;
      }
      
      for (int i = 0; i < nums.size(); i++) {
        if (!visited[i]) {
          visited[i] = true;
          current.push_back(nums[i]);
          backTracking(nums, visited, result, current);
          
          visited[i] = false;
          current.pop_back();
        }
      }
    }
  
    vector<vector<int>> permute(vector<int>& nums) {
      vector<vector<int>> result;
      if (nums.empty()) {
        return result;
      }
      vector<bool> visited(nums.size(), false);
      vector<int> current;
      backTracking(nums, visited, result, current);
      return result;
    }
};