class Solution {
public:
    int maxSubarrayLength(vector<int>& a, int k) {
        int n = a.size();
        int l = 0;
        int r = 0;
        map<int,int>mp;
        int ans = 0;
        while(r<n && l<=r){
            mp[a[r]]++;
                while(mp[a[r]]>k){
                    mp[a[l]]--;
                    l++;
                }
            ans = max(ans , r-l+1);
            r++;
        }
        return ans ;
    }
};