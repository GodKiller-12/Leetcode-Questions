class Solution {
public:
int mod = 1e9 +7 ;

 int rec(int ind ,vector<vector<int>>&pref,string &s,vector<int>&dp){
    int n = s.size();
    cout<<ind<<" ";
            if(ind == n){
                 return 1;
            }
            if(dp[ind]!=-1) return dp[ind]%mod;
           
            int ans = 1;
            
            for(int j = 0;j<26;j++){
                if(pref[ind][j]!=n){
                    ans = (ans%mod + rec(pref[ind][j],pref,s,dp)%mod)%mod;
                }
            }
            return dp[ind] = ans%mod ;
        }

    int distinctSubseqII(string s) {
    
       int n = s.size();
       vector<int>dp(n+1,-1);
        vector<vector<int>>pref(n+1,vector<int>(26,n));
        vector<int>occ(26,n);
        for(int i = n-1;i>=0;i--){
            for(int j = 0;j<26;j++){
                pref[i][j] = occ[j];
            }
            occ[s[i]-'a'] = i;
        }
int res = 0;
// for(auto i :occ){
//     cout<<i<<" ";
// }
// cout<<endl;
    for(int j = 0;j<26;j++){
        if(occ[j]!=n){
        res = (res%mod + rec(occ[j],pref,s,dp)%mod)%mod;
        }
    }

// cout<<res<<endl;
return (res+ mod)%mod;

    }
};