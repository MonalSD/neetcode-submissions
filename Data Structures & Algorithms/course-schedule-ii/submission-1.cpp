class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int>ans;
        vector<int>indegree(numCourses,0);
        unordered_map<int,vector<int>>mp;
        queue<int> q;
        for(auto it:prerequisites){
            mp[it[1]].push_back(it[0]);
            indegree[it[0]]++;
        }

        for(int i=0;i<numCourses;i++){
            if(indegree[i]==0)
                q.push(i);
        }
        int count =0;
        while(!q.empty()){
            int curr = q.front();
            count++;
            q.pop();
            ans.push_back(curr);
            for(auto j:mp[curr]){
                indegree[j]--;
                if(indegree[j]==0)
                    q.push(j);
            }
        }
        return count == numCourses ? ans : vector<int>{};
    }
};
