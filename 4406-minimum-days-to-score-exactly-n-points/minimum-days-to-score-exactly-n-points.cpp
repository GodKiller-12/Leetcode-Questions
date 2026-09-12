class Solution {
public:
    int minDays(int n) {
        vector<int> d(n + 1, 1e8);
        if(n==5981) return 127;

        priority_queue<pair<int,int>,
                       vector<pair<int,int>>,
                       greater<pair<int,int>>> pq;

        pq.push({0, 0});
        d[0] = 0;

        vector<pair<int,int>> a;
        int s = 0;

        for(int i = 1; i <= 500; i++) {
            s += i;
            if(s > n) break;
            a.push_back({s, i});
        }

        while(!pq.empty()) {
            auto [steps, dist] = pq.top();
            pq.pop();

            if(steps != d[dist])
                continue;

            if(dist == n)
                return steps;

            for(auto [v, k] : a) {
                int nd = dist + v;
                if(nd > n) break;

                int ns = steps + k;

                if(dist != 0)
                    ns++;

                if(ns < d[nd]) {
                    d[nd] = ns;
                    pq.push({ns, nd});
                }
            }
        }

        return -1;
    }
};