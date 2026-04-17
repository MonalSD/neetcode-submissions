class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        vector<bool> visited(strs.size(), false);

        for (int i = 0; i < strs.size(); i++) {
            if (visited[i]) continue;

            vector<string> res;
            res.push_back(strs[i]);
            visited[i] = true;

            for (int j = i + 1; j < strs.size(); j++) {
                if (!visited[j] && strs[i].size() == strs[j].size()) {
                    if (isAnagram(strs[i], strs[j])) {
                        res.push_back(strs[j]);
                        visited[j] = true;
                    }
                }
            }

            ans.push_back(res);
        }

        return ans;
    }

    bool isAnagram(string s, string t) {
        unordered_map<char, int> freq1;
        unordered_map<char,int> freq2;

        for (char ch : s) {
            freq1[ch]++;
        }

        for (char ch : t) {
            freq2[ch]++;
        }

        return freq1 == freq2;
    }
};
