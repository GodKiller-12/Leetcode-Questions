class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();

        vector<pair<int,int>> a;
        for(int i = 0; i < n; i++)
            a.push_back({nums[i], i});

        sort(a.begin(), a.end());

        vector<int> ans(n);

        int l = 0;

        while(l < n) {
            int r = l;

            while(r + 1 < n && a[r + 1].first - a[r].first <= limit)
                r++;

            multiset<int> s;

            for(int i = l; i <= r; i++)
                s.insert(a[i].first);

            vector<int> id;
            for(int i = l; i <= r; i++)
                id.push_back(a[i].second);

            sort(id.begin(), id.end());

            for(int p : id) {
                auto it = s.lower_bound(a[l].first);

                ans[p] = *it;
                s.erase(it);
            }

            l = r + 1;
        }

        return ans;
    }
};