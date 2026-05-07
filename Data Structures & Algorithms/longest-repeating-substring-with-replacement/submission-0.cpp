class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char,int> mp;
        int l=0;
        int maxf = 0;
        int ans = 0;

        for(int r=0;r<s.size();r++){
            mp[s[r]]++;
            maxf= max(maxf,mp[s[r]]);

            int win = r-l+1;
            while(win-maxf > k){
                mp[s[l]]--;
                l++;
                win = r-l+1;
            }
            ans = max(ans,r-l+1);
        }

        return ans;
    }
};
