class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int>degree(edges.size()+1,0);
        vector<vector<int>> mp(edges.size()+1);
        queue<int> q;
        for(auto it:edges){
            mp[it[1]].push_back(it[0]);
            mp[it[0]].push_back(it[1]);
            degree[it[0]]++;
            degree[it[1]]++;
        }

        for(int i=1;i<=edges.size();i++){
            if(degree[i]==1)
                q.push(i);
        }

        while(!q.empty()){
            int curr = q.front();
            q.pop();
            degree[curr]--;
            for(auto j:mp[curr]){
                degree[j]--;
                if(degree[j]==1)
                    q.push(j);
            }
        }
        

        for(int i= edges.size()-1;i>=0;i--){
            int u = edges[i][0];
            int v = edges[i][1];

            if (degree[u] > 0 && degree[v] > 0) {
                return edges[i];
            }
        }

        return {};
        
        
    }
};
