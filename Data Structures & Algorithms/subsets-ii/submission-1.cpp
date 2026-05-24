class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        vector<int> sub;
        recur(ans,sub,nums,0);
        return ans;
    }

    void recur(vector<vector<int>>& ans,vector<int>& sub,vector<int>& nums,int start){
        ans.push_back(sub);

        for(int i=start;i<nums.size();i++){
            if(i>start && nums[i]==nums[i-1])
                continue;
            sub.push_back(nums[i]);
            recur(ans,sub,nums,i+1);
            sub.pop_back();
        }
    }
};
