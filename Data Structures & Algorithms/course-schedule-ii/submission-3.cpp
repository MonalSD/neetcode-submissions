class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int>ans;
        vector<int>indegree(numCourses,0);
        vector<vector<int>> mp(numCourses);
        queue<int> q;
        for(auto it:prerequisites){
            mp[it[1]].push_back(it[0]);
            indegree[it[0]]++;
        }

        for(int i=0;i<numCourses;i++){
            if(indegree[i]==0)
                q.push(i);
        }

        while(!q.empty()){
            int curr = q.front();
            q.pop();
            ans.push_back(curr);
            for(auto j:mp[curr]){
                indegree[j]--;
                if(indegree[j]==0)
                    q.push(j);
            }
        }
        return ans.size() == numCourses ? ans : vector<int>{};
    }
};
