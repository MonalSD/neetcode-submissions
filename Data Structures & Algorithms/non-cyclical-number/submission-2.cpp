class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int>visit;

        while(n!=1 && visit.find(n)==visit.end()){
            visit.insert(n);
            int x = n;
            int sum =0;
            while(x>0){
                int temp = x%10;
                sum = sum+temp*temp;
                x = x/10;
            }
            
            n=sum;
        }
        return n==1;
    }
};
