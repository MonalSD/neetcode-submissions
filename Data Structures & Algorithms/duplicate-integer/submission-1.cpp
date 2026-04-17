class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> s;
        int i=0;
        for(int x: nums){
            s.insert(nums[i]);
            i++;
        }
        if(nums.size()!=s.size())
            return true;
        else
            return false;
    }
};