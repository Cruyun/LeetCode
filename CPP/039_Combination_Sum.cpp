// backtracking
class Solution {
public:
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
      sort(candidates.begin(), candidates.end());
      vector<vector<int> > result;
      vector<int> temp;
      combinate(candidates, target, result, temp, 0);
      return result;
    }
private:
    void combinate(vector<int> &candidates, int target, vector<vector<int>> &result, vector<int> &temp, int begin) {
      if (!target) {
        result.push_back(temp);
        return;
      }

      for (int i = begin; i < candidates.size() && candidates[i] <= target; i++) {
        temp.push_back(candidates[i]);
        combinate(candidates, target - candidates[i], result, temp, i);
        temp.pop_back();
      }
    }
};