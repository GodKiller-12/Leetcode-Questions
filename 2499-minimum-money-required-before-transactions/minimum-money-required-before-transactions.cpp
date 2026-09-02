class Solution {
public:
    long long minimumMoney(vector<vector<int>>& t) {
        //  binary search + greedy 
        // at last you can consider the most negative one , like you can push
        // consider the worst order 
        int n = t.size();
        vector<int>a;
        // positives me bhi worst case consider krna hai ki max positive moneyh wale ke sath match krna chahiye jaise hi positive ho jaye number
// +ve wale number koi dikkat nahi denge bas negative wale hi denge to unko baad me ya kis bhi order me place kro doesnt matter , baki sab s
long long neg = 0;
int maxi = 0;
        for(int i = 0;i<n;i++){
            int val = t[i][1]-t[i][0];
            if(val >=0) {
                maxi = max(maxi , t[i][0]);
                continue ;
            }
            neg += val ;
        }
        cout<<neg;
        long long ans = 0;
        for(int i = 0;i<n;i++){
             int val = t[i][1]-t[i][0];
            if(val >=0) continue ;
            ans = max(ans , -1LL*(neg +t[i][0]- t[i][1]) + t[i][0]);
        }
        long long p = ans ;
        ans = ans + neg ;
        p += max(0LL , (long long)maxi - ans );
        return p ;

        // int lo = 0;
        // int hi = 1e9 ;
        // while(lo<=hi){
        //     int mid = (lo + hi)/2 ;
        //     if(check(a ,))
        // }
    }
};