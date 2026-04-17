class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> s;
        int i=0;
        for(int x: nums){
            s.insert(nums[i]);
            i++;
        }
        return s.size()!=nums.size();
    }
};