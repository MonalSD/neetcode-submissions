class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s(nums.begin(),nums.end());
        int ans=0;
        for(int it: s){
            if(!s.count(it-1)){
                int count =1;
                int i = it;
                while(s.count(i+1)){
                    count++;
                    i++;
                }
                ans = max(ans,count);
            }
        }
        return ans;
    }
};
