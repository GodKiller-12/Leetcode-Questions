#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
class Solution { 
public: 
    long long distantSubarrays(vector<int>& nums, int goal, int k) { 
        
         // for each l i need to found r such that abs(sum-goal)>=k 
        //  no of r whose prefix sum - currsum >= x1 
        // and no of r whose prefix sum - currsum <= x2 
        // sare prefix sum insert krke lower bound laga lo aur dono ko add kr lo  
        // x1 and x2 goal se k units dur wale points hai  

        int n = nums.size();
        if(k == 0) return 1LL * n * (n + 1) / 2;
        vector<long long> p(n + 1);

        for(int i = 0; i < n; i++) p[i + 1] = p[i] + nums[i];

        using T = pair<long long,int>;
        tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update> s;

        for(int i = 0; i <= n; i++) s.insert({p[i], i});

        long long ans = 0;

        for(int i = 0; i < n; i++){
            s.erase({p[i], i});

            long long x1 = p[i] + goal + k;
            long long x2 = p[i] + goal - k;

            ans += s.size() - s.order_of_key({x1, -1});
            ans += s.order_of_key({x2, n + 1});
        }

        return ans;
    } 
};