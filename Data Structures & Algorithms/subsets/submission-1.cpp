class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> subset;
        vector<vector<int>> res;
        int start =0; 
        rcur(res,subset,0,nums);
        return res;
    }
    void rcur(vector<vector<int>>& res,vector<int>& subset,int start,vector<int>&nums){
        res.push_back(subset);
        for(int i=start;i<nums.size();i++){
            subset.push_back(nums[i]);
            rcur(res,subset,i+1,nums);
            subset.pop_back();
        }
        return;
    }
};
