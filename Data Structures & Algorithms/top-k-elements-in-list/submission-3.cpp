class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;

        for (int x : nums) {
            mp[x]++;
        }

        vector<vector<int>> pm(nums.size() + 1);

        for (auto &it : mp) {
            int num = it.first;
            int freq = it.second;

            pm[freq].push_back(num);
        }

        vector<int> ans;

        for (int freq = pm.size() - 1; freq >= 0; freq--) {
            for (int num : pm[freq]) {
                ans.push_back(num);

                if (ans.size() == k) {
                    return ans;
                }
            }
        }

        return ans;
    }
};