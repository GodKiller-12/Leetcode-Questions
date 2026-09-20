class Solution {
public:
    vector<vector<int>> subsets(vector<int>& a) {
        int n = a.size();
        int count = (1<<n) - 1;
        vector<vector<int>>ans(count+1);
        for(int i = 0;i<=count;i++){
            for(int j = 0;j<n;j++){
                if((1<<j)&(i)){
                  ans[i].push_back(a[j]);
                }
            }
        }
        return ans ;
    }
};