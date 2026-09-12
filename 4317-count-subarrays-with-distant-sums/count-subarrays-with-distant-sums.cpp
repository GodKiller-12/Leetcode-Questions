class Solution { 
public: 
    long long distantSubarrays(vector<int>& nums, int goal, int k) { 
         // for each l i need to found r such that abs(sum-goal)>=k 
        //  no of r whose prefix sum - currsum >= x1 
        // and no of r whose prefix sum - currsum <= x2 
        // sare prefix sum insert krke lower bound laga lo aur dono ko add kr lo  
        // x1 and x2 goal se k units dur wale points hai  

        int n = nums.size();
        vector<long long> p(n + 1);
if(k == 0) return 1LL * n * (n + 1) / 2;
        for(int i = 0; i < n; i++) p[i + 1] = p[i] + nums[i];

        vector<long long> v = p;
        sort(v.begin(), v.end());
        v.erase(unique(v.begin(), v.end()), v.end());

        int m = v.size();
        vector<int> bit(m + 1);

        auto add = [&](int x, int val){
            for(; x <= m; x += x & -x) bit[x] += val;
        };

        auto sum = [&](int x){
            int r = 0;
            for(; x > 0; x -= x & -x) r += bit[x];
            return r;
        };

        for(auto x : p){
            int id = lower_bound(v.begin(), v.end(), x) - v.begin() + 1;
            add(id, 1);
        }

        long long ans = 0;

        for(int i = 0; i < n; i++){
            int id = lower_bound(v.begin(), v.end(), p[i]) - v.begin() + 1;
            add(id, -1);

            long long x1 = p[i] + goal + k;
            long long x2 = p[i] + goal - k;

            int a = lower_bound(v.begin(), v.end(), x1) - v.begin();
            int b = upper_bound(v.begin(), v.end(), x2) - v.begin();

            ans += sum(m) - sum(a);
            ans += sum(b);

        }

        return ans;
    } 
};