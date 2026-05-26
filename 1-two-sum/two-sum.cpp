class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp;

        for (int i = 0; i < nums.size(); i++) {
            int needed = target - nums[i];

            // Check if needed number already exists
            if (mp.find(needed) != mp.end()) {
                return {mp[needed], i};
            }

            // Store current number with index
            mp[nums[i]] = i;
        }

        return {};
    }
};