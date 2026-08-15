class Solution {
public:
    int longestSubsequence(vector<int>& a) {
        int n = a.size();
        bool ok = false ;
        for(int i = 31;i>=0;i--){
            int count = 0;
            for(int j = 0;j<n;j++){
                if(a[j]&(1<<i)){
                    count ++;
                }
            }
            if(count >0){
                ok = true ;

            }
            if(count%2==1){
                return n;
            }
        }
        if(!ok) return 0;
        return n-1;
    }
};