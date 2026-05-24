class Solution {
public:
    vector<string> digitToChar = {
            "", "", "abc", "def", "ghi", "jkl",
            "mno", "qprs", "tuv", "wxyz"
        };
    vector<string>res;
    vector<string> letterCombinations(string digits) {
        if(digits.empty())
            return res;
        recur(0,"",digits);
        return res;
    }
    void recur(int i,string curr,string & digits){
        if(curr.size()==digits.size()){
            res.push_back(curr);
            return;
        }
        string ch = digitToChar[digits[i]-'0'];
        for(char c: ch)
            recur(i+1,curr+c,digits);
    }
};
