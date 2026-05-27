class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1=="0" || num2=="0")
            return "0";
        int n = num1.size();
        int m = num2.size();
        vector<int> res(n+m,0);
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                int d1 = num1[i]-'0';
                int d2 = num2[j]-'0';

                int mul = d1*d2;
                int sum = mul+res[i+j+1];

                res[j+i+1] = sum%10;
                res[j+i] += sum/10;
            }
        }

        string ans="";

        for(int i:res){
            if (!(ans.empty() && i == 0)) {
                ans.push_back(i + '0');
            }
        }

        return ans;
        
        
    }
    
};
