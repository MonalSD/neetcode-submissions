class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> mp;
        vector<int>indegree(numCourses,0);
        queue<int> q;
        for (auto it : prerequisites) {
            mp[it[1]].push_back(it[0]);
            indegree[it[0]]++;
        }

        for(int i =0;i<numCourses;i++){
            if(indegree[i]==0)
                q.push(i);
        }
        if(q.empty())
            return false;
        int count =0;
        while(!q.empty()){
            int curr= q.front();
            q.pop();
            count++;
            for(int j:mp[curr]){
                indegree[j]--;
                if(indegree[j]==0)
                    q.push(j);
            }
        }
        return count==numCourses;




    }
};
