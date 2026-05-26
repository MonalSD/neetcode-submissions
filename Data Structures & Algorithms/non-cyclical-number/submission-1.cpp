class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int>visit;

        while(visit.find(n)==visit.end()){
            visit.insert(n);
            n=sumofsquares(n);
            if(n==1)
                return true;
        }
        return false;
    }

    int sumofsquares(int n){
        int sum = 0;
        while(n>0){
            int x = n%10;
            sum = sum+x*x;
            n=n/10;
        }
        return sum;
    }
};
