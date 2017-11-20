class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        map<int, int> match;
        int matchNum;
        
        for (int i = 0; i < nums.size(); i++) {
            matchNum = target - nums[i];
            
            if (match.find(matchNum) != match.end()) {
                result.push_back(match[matchNum]);
                result.push_back(i);
                return result;
            }
            match[nums[i]] = i;
        }
        
    }
};