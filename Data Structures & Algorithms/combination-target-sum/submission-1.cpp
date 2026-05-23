class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>res;
        vector<int> sub;
        recur(res,sub,nums,target,0,0);
        return res;

    }
    void recur(vector<vector<int>>& res,vector<int>& sub,vector<int>&nums,int target,int sum,int start){
        if(sum==target){
            res.push_back(sub);
            return;
        }

        for(int i = start;i<nums.size();i++){
            if(sum+nums[i]>target)
                return;
            sub.push_back(nums[i]);
            recur(res,sub,nums,target,sum+nums[i],i);
            sub.pop_back();
        }
    }
};
