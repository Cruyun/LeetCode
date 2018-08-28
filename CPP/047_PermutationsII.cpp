class Solution {
public:
    void backTracking(vector<int>& nums, vector<bool>& visited, vector<vector<int>>& result, vector<int> current) {
      if (current.size() == nums.size()) {
        result.push_back(current);
        return;
      }
      
      for (int i = 0; i < nums.size(); i++) {
        //if( i > 0 && nums[i] == nums[i-1] && !visited[i - 1] ) continue; 此方法也可以
        if (!visited[i]) {
          visited[i] = true;
          current.push_back(nums[i]);
          backTracking(nums, visited, result, current);
          
          visited[i] = false;
          current.pop_back();
          while (i < nums.size() && nums[i] == nums[i + 1]) i++; // 后面与这个元素相同的元素都可以pass掉,在递归的出口处处理
        }
      }
    }
  
    vector<vector<int>> permuteUnique(vector<int>& nums) {
      vector<vector<int>> result;
      if (nums.empty()) {
        return result;
      }
      sort(nums.begin(), nums.end()); // 排序以便后面过滤
      vector<bool> visited(nums.size(), false);
      vector<int> current;
      backTracking(nums, visited, result, current);
      return result;
    }
};