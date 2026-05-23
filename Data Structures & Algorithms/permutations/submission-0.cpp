class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> sub;
        vector<bool> pick(nums.size(),false);
        recur(res,sub,nums,pick);
        return res;
    }
    void recur(vector<vector<int>>& res,vector<int>& sub,vector<int>& nums,vector<bool>& pick){
        if(sub.size()==nums.size()){
            res.push_back(sub);
            return;
        }

        for(int i=0;i<nums.size();i++) {
            if(!pick[i]){
                sub.push_back(nums[i]);
                pick[i]=true;
                recur(res,sub,nums,pick);
                sub.pop_back();
                pick[i]=false;
            }
        }

    }
};
