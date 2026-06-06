class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        int ans =0;
        vector<bool> visit(n,false);
        vector<vector<int>> mp(n);
        for(auto it: edges){
            mp[it[0]].push_back(it[1]);
            mp[it[1]].push_back(it[0]);
        }
        for(int i=0;i<n;i++){
            if(!visit[i]){
                bfs(visit,mp,i);
                ans++;
            }
        }
        return ans;

        
    }
    void bfs(vector<bool>& visit,vector<vector<int>>& mp,int node){
        queue<int>q;
        q.push(node);
        visit[node]=true;
        while(!q.empty()){
            int curr = q.front();
            q.pop();
            for(int j:mp[curr]){
                if(visit[j]!=true){
                    q.push(j);
                    visit[j]=true;
                }
            }
        }
    }
};
