class Solution { 
public: 
    int nthMagicalNumber(int n, int a, int b) { 
        // 2  3 4 6 8 9 10 12 14 15 16 18  
        // lcm ke sare multiple repeat honge  
        // 4 6  
        // 4 6 8 12 16 18 20 24  
        // same numberof element before lcm 
        // nth number 
        // n/(lcm/a -1 + lcm/b ) will be the itne ke baad repeat hoga  
        // lcm * n/(lcm/a - 1 + lcm/b) + mod  
        // agar lcm na hota to nth number me check krte kitne a wale aaye hai  
        int mod = 1000000007;
        int p = lcm(a,b); 
        int q = p/a ; 
        int r = p/b ; 

        int d = q+r-1;
        if(d == 0) return 0;
        int k = (1ll*p*((n-1)/d)) % mod; 
        int ans = 0;
        int req = (n-1)%d+1;
        int i = 1 , j = 1; 
        while(req--){ 
            if(a*i < b*j) ans = (a*i)%mod,i++; 
            else ans = (b*j)%mod,j++; 
        } 
        ans = (ans + k)%mod;
        return ans % mod; 
    } 
};