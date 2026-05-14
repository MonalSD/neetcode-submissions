class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            int x = abs(nums[i]);
            int idx = x - 1;

            if (nums[idx] < 0) {
                return x;
            }

            nums[idx] *= -1;
        }

        return -1;
    }
};
