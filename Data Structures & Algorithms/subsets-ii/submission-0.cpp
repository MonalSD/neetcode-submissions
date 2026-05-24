class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int> sub;

        set<vector<int>> st;
        recur(st,sub,nums,0);
        vector<vector<int>> ans(st.begin(), st.end());
        return ans;
    }

    void recur(set<vector<int>>& st,vector<int>& sub,vector<int>& nums,int start){
        st.insert(sub);
        for(int i=start;i<nums.size();i++){
            sub.push_back(nums[i]);
            recur(st,sub,nums,i+1);
            sub.pop_back();
        }
    }
};
