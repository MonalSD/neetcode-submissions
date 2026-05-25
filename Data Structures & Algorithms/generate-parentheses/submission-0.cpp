class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string>res;
        recur("",res,n);
        return res;
    }
    void recur(string s,vector<string>& res,int n){
        if(s.length()==2*n){
            if(valid(s))
                res.push_back(s);
            return;
        }
        recur(s+'(',res,n);
        recur(s+')',res,n);
    }
    bool valid(string&s){
        int open =0;
        for(char c:s){
            if(c=='(')
                open++;
            else
                open--;
            
            if(open<0)
                return false;
        }
        return open==0;
    }
};
