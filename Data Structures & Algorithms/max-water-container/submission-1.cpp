class Solution {
public:
    int maxArea(vector<int>& h) {
        int ans = 0;

        int i = 0;
        int j = h.size()-1;

        while(i<j){
            int area = (j-i)*min(h[i],h[j]);
            ans = max(ans,area);

            if(h[j]>h[i])
                i++;
            else
                j--;
        }
        return ans;
    }
};
