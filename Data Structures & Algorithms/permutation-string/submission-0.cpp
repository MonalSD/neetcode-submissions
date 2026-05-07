class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int k = s1.size();
        unordered_map<char,int> mp1;
        unordered_map<char,int> mp2;
        bool ans = false;
        for(auto it:s1){
            mp1[it]++;
        }
        int i =0;
        int j =0;
        while(j<s2.size()){
            mp2[s2[j]]++;
            if(j-i+1<k){
                j++;
            }
            else if(j-i+1==k){
                if(mp1 == mp2){
                    ans = true;
                    break;
                }
                else{
                    if (--mp2[s2[i]] == 0) mp2.erase(s2[i]);
                    i++;
                    j++;
                }
            }
        }
        return ans;
    }
};
