class Solution {
public:
class DSU {
    vector<int> parent, size;

public:
    DSU(int n) {
        parent.resize(n);
        size.assign(n, 1);
        iota(parent.begin(), parent.end(), 0);
    }

    int find(int x) {
        if (parent[x] == x)
            return x;

        return parent[x] = find(parent[x]);  
    }

    bool unite(int a, int b) {
        a = find(a);
        b = find(b);

        if (a == b)
            return false;

        if (size[a] < size[b])
            swap(a, b);

        parent[b] = a;
        size[a] += size[b];

        return true;
    }

    bool connected(int a, int b) {
        return find(a) == find(b);
    }

    int sz(int x) {
        return size[find(x)];
    }
};

    int minCapability(vector<int>& a, int k) {
        int n =a.size();
       vector<pair<int,int>>v;
       for(int i = 0;i<n;i++){
        v.push_back({a[i],i});
       }
 DSU ds(n);
 set<int>st;
       sort(v.begin(),v.end());
       int count =0;
       for(int i = 0;i<n;i++){
          int num = v[i].second;
          if(st.find(num-1)!=st.end() && st.find(num+1)!=st.end()){
            int total = ds.sz(ds.find(num-1));
            count -= (total +1)/2;
            total = ds.sz(ds.find(num+1));
            count -= (total + 1)/2;
            ds.unite(num-1,num);
            ds.unite(num+1,num);
            count += (ds.sz(ds.find(num))+1)/2;
          }
          else if(st.find(num-1)!=st.end()){
            int total = ds.sz(ds.find(num-1));
            count -= (total +1)/2;
            ds.unite(num-1,num);
            count += (ds.sz(ds.find(num))+1)/2;


          }else if(st.find(num+1)!=st.end()){
            int total = ds.sz(ds.find(num+1));
            count -= (total +1)/2;
            ds.unite(num+1,num);
            count += (ds.sz(ds.find(num))+1)/2;
          }
          else{
            ds.unite(num,num);
            count += (ds.sz(ds.find(num))+1)/2;
          }
          if(count >= k) return v[i].first ;
        
        st.insert(v[i].second);
       }
return 0;
        
    }
};