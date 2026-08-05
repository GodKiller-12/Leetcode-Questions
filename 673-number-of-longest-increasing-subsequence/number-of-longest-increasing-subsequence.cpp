class Solution {
public:
    struct BIT {
        int n;
        vector<pair<int,long long>> bit;

        BIT(int n) : n(n) {
            bit.assign(n + 1, {0, 0});
        }

        pair<int,long long> merge(pair<int,long long> a,
                                  pair<int,long long> b) {
            if(a.first > b.first) return a;
            if(b.first > a.first) return b;
            if(a.first == 0) return {0, 0};
            return {a.first, a.second + b.second};
        }

        void update(int idx, pair<int,long long> val) {
            while(idx <= n) {
                bit[idx] = merge(bit[idx], val);
                idx += idx & -idx;
            }
        }

        pair<int,long long> query(int idx) {
            pair<int,long long> res = {0,0};

            while(idx > 0) {
                res = merge(res, bit[idx]);
                idx -= idx & -idx;
            }

            return res;
        }
    };

    int findNumberOfLIS(vector<int>& nums) {

        vector<int> comp = nums;
        sort(comp.begin(), comp.end());
        comp.erase(unique(comp.begin(), comp.end()), comp.end());

        int m = comp.size();

        BIT ft(m);

        for(int x : nums) {

            int pos =
                lower_bound(comp.begin(), comp.end(), x)
                - comp.begin() + 1;

            auto [len, cnt] = ft.query(pos - 1);

            if(len == 0) cnt = 1;

            ft.update(pos, {len + 1, cnt});
        }

        auto ans = ft.query(m);

        return (int)ans.second;
    }
};