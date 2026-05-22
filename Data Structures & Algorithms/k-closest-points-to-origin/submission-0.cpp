class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int,int>> maxh;
        for(int i=0;i<points.size();i++){
            long long dist = points[i][0]*points[i][0]+points[i][1]*points[i][1];

            maxh.push({dist,i});
            if(maxh.size()>k){
                maxh.pop();
            }
        }
        vector<vector<int>> ans;

        while(!maxh.empty()){
            ans.push_back(points[maxh.top().second]);
            maxh.pop();
        }
        return ans;
    }
};
