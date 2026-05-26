class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int>a;
        long long digit = 0;
        for(int i=0;i<digits.size();i++){
            digit = digit + digits[i]*pow(10,digits.size()-(1+i));
        }
        long long ans = digit+1;
        while(ans>0)
        {
            int x = ans%10;
            a.push_back(x);
            ans = ans/10;
        }
        reverse(a.begin(),a.end());

        return a;

    }
};
