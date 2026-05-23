class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& can, int target) {
        sort(can.begin(),can.end());
        vector<vector<int>> res;
        vector<int> sub;
        recur(res,sub,can,target,0,0);
        return res;
    }
    void recur(vector<vector<int>>& res,vector<int>& sub,vector<int>& can, int target,int sum,int start){
        if(sum==target){
            res.push_back(sub);
            return;
        }
        for(int i = start;i<can.size();i++){
            if(sum+can[i]>target)
                break;
            if(i>start && can[i]==can[i-1])
                continue;
            sub.push_back(can[i]);
            recur(res,sub,can,target,sum+can[i],i+1);
            sub.pop_back();
        }
    }
};
