vector<vector<int>> threeSum(vector<int>& nums) {
  vector<vector<int>> result;
  if (nums.size() <= 2) {
    return result;
  }
  sort(nums.begin(), nums.end());
  for (int i = 0; i < nums.size(); i++) {
    int a = nums[i];
    if (a > 0) break;
    if (a == nums[i - 1] && i > 0) continue;

    int j = i + 1;
    int k = nums.size() - 1;
    while (j < k) {
      int b = nums[j];
      int c = nums[k];
      int sum = a + b + c;
      if (sum == 0 ) {
        result.push_back(vector<int>({a, b, c}));
        while (b == nums[++j]);
        while (c == nums[--k]);
      } else if (sum > 0) {
        k--;
      } else {
        j++;
      }
    }
  }
  return result;
}