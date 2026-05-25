class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string>res;
        recur("",res,n,0,0);
        return res;
    }
    void recur(string s,vector<string>& res,int n,int open,int close){
        if(s.length()==2*n){
            res.push_back(s);
            return;
        }

        if(open<n){
            recur(s+'(',res,n,open+1,close);
        }
        if(close<open){
            recur(s+')',res,n,open,close+1);
        }
        
    }
};
