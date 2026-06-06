class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if(edges.size()!=n-1)
            return false;
        
        vector<vector<int>> mp(n);

        for (auto it : edges) {
            mp[it[0]].push_back(it[1]);
            mp[it[1]].push_back(it[0]);
        }
        vector<bool> visited(n,false);
        queue<int>q;
        q.push(0);
        visited[0]=true;
        int count =0;

        while(!q.empty()){
            int curr = q.front();
            q.pop();
            count++;
            for(auto j:mp[curr]){
                if(!visited[j]){
                    visited[j]=true;
                    q.push(j);
                }
            }
        }

        return count==n;


    }
};
