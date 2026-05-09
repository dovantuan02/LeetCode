class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int arr_idx = nums.size();
        for (int i = 0; i < arr_idx - 1; i++) {
            for (int j = i + 1; j < arr_idx; j++) {
                int  num = nums[i] + nums[j];
                if (num == target) {
                    return {i, j};
                }
            }
        }
        return {};
    }
};