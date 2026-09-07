class Solution {
    using ll=long long;
public:
    int n;
    int maxbits;
    vector<vector<pair<int,int>>>adj;
    vector<int>depth;
    vector<vector<int>>up;
    vector<vector<int>>f;

    void dfs(int u,int v){
        up[u][0]=v;

        depth[u]=(u==0?0:depth[v]+1);
        for(auto [nb,w]:adj[u]){
            if(nb==v)continue;
            f[nb]=f[u];
            f[nb][w]+=1;
            dfs(nb,u);
        }
    }

    void BinaryLifting(){
        maxbits=log2(n)+2;
        up.assign(n,vector<int>(maxbits));
        depth.assign(n,-1);

        dfs(0,0);

        for(int j=1;j<maxbits;j++){
            for(int i=0;i<n;i++){
                up[i][j]=up[up[i][j-1]][j-1];
            }
        }
    }

    int kthAncestor(int x,int k){
        if(depth[x]<k)return -1;

        for(int j=0;j<maxbits;j++){
            if(k&(1<<j)){
                x=up[x][j];
            }
        }
        return x;
    }

    int lca(int u, int v){
        if(depth[u]>depth[v])u=kthAncestor(u,depth[u]-depth[v]);
        else if(depth[u]<depth[v])v=kthAncestor(v,depth[v]-depth[u]);

        if(u==v)return u;
        for(int i=maxbits-1;i>=0;i--){
            if(up[u][i]!=up[v][i]){
                u=up[u][i];
                v=up[v][i];
            }
        }
        return up[u][0];
    }
    vector<int> minOperationsQueries(int N, vector<vector<int>>& edges, vector<vector<int>>& queries) {
        n=N;
        adj.assign(n,{});
        for(auto &e:edges){
            adj[e[0]].push_back({e[1],e[2]});
            adj[e[1]].push_back({e[0],e[2]});
        }
        
        f.assign(n,vector<int>(27,0));
        BinaryLifting();
        
        vector<int>ans;
        for(auto q:queries){
            int l=lca(q[0],q[1]);

            int maxi=0;
            int d=depth[q[0]]+depth[q[1]]-2*depth[l];
            for(int i=0;i<27;i++){
                maxi=max(maxi,f[q[0]][i]+f[q[1]][i]-2*f[l][i]);
            }
            ans.push_back(d-maxi);
        }
        return ans;
    }
};